#ifndef LIBLDPC_CPP
#define LIBLDPC_CPP

#include "libldpc.h"

std::vector<bool> LibLDPC::Encoder(std::vector<bool> &vkey, const double _qber, int seed)
{
    using namespace std;
    double r = 0;
    if(_qber <= 0.01) r = 0.85;
    if(_qber > 0.01 && _qber <= 0.02) r = 0.75;
    if(_qber > 0.02 && _qber <= 0.03) r = 0.65;
    if(_qber > 0.03 && _qber <= 0.04) r = 0.63;
    if(_qber > 0.04 && _qber <= 0.05) r = 0.55;
    if(_qber > 0.05 && _qber <= 0.06) r = 0.53;
    if(_qber > 0.06 && _qber <= 0.07) r = 0.52;
    if(_qber > 0.07 && _qber <= 0.08) r = 0.47;
    if(_qber > 0.08 && _qber <= 0.09) r = 0.45;
    if(_qber > 0.09 && _qber <= 0.1) r = 0.35;
    if(_qber > 0.1){ r = 0.30; }
    int s = int(vkey.size()/r)+1;

    LDPCCode ldpccode(s - vkey.size(), s, seed, LDPCMakeLDPC::Evenboth, "5x2/4x3/1x7", true);
    //ldpccode.savetofile("matrix");

    LDPCEncode encode(ldpccode);

    QByteArray encodedKey, key;
    for(int i = 0; i < vkey.size(); i++)
        if(vkey[i])
            key.push_back(1);
        else
            key.push_back(char(0));
    encode.encode(key, encodedKey);
    vector<bool> ldpcCode;

    BSCinfo channelinfo;
    channelinfo.error_prob = _qber;

    Prprpinfo decodingmethodinfo;
    decodingmethodinfo.max_iterations=200;

    LDPCDecode decode(ldpccode, channelinfo, decodingmethodinfo);

    decode.extractLDPC(encodedKey, ldpcCode);

    return ldpcCode;
}

std::vector<bool> LibLDPC::Decoder(
    std::vector<bool> &vkey,
    std::vector<bool> &ldpcCode,
    const double _qber,
    int seed)
{
    using namespace std;
    //LDPCCode ldpccode(filename);
    LDPCCode ldpccode(ldpcCode.size(), ldpcCode.size() + vkey.size(),seed,LDPCMakeLDPC::Evenboth,"5x2/4x3/1x7",true);

    BSCinfo channelinfo;
    channelinfo.error_prob = _qber;

    Prprpinfo decodingmethodinfo;
    decodingmethodinfo.max_iterations=200;

    LDPCDecode decode(ldpccode, channelinfo, decodingmethodinfo);

    QVector<double> dKey;
    decode.includeLDPC(vkey, ldpcCode, dKey);

    QByteArray decodedKey;
    decode.decode(dKey, decodedKey);

    decode.extract(decodedKey);
    vector<bool> key(decodedKey.size());
    for(int i = 0; i < decodedKey.size(); i++)
    {
        if(decodedKey.at(i) == 0)
            key[i] = 0;
        else
            key[i] = 1;
    }

    return key;
}

#endif //! LIBLDPC_CPP
