#ifndef LIBLDPC_CPP
#define LIBLDPC_CPP

#include "libldpc.h"

#include <vector>
#include <iostream>

std::vector<bool> LibLDPC::Encoder(
    std::vector<bool> &vkey,
    const double _qber,
    int seed)
{
    using namespace std;
    double r = 0;
    size_t sr;
    
    if(_qber <= 0.01)                 sr = 0;
    if(_qber > 0.01 && _qber <= 0.02) sr = 1;
    if(_qber > 0.02 && _qber <= 0.03) sr = 2;
    if(_qber > 0.03 && _qber <= 0.04) sr = 3;
    if(_qber > 0.04 && _qber <= 0.05) sr = 4;
    if(_qber > 0.05 && _qber <= 0.06) sr = 5;
    if(_qber > 0.06 && _qber <= 0.07) sr = 6;
    if(_qber > 0.07 && _qber <= 0.08) sr = 7;
    if(_qber > 0.08 && _qber <= 0.09) sr = 8;
    if(_qber > 0.09 && _qber <= 0.1)  sr = 9;
    if(_qber > 0.1)                   sr = 10;

    int s = int(vkey.size()/speeds[sr])+1;

    LDPCEncode encode(memory[sr]);

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

    LDPCDecode decode(memory[sr], channelinfo, decodingmethodinfo);

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

    BSCinfo channelinfo;
    channelinfo.error_prob = _qber;

    Prprpinfo decodingmethodinfo;
    decodingmethodinfo.max_iterations=200;

    size_t sr;
    
    if(_qber <= 0.01)                 sr = 0;
    if(_qber > 0.01 && _qber <= 0.02) sr = 1;
    if(_qber > 0.02 && _qber <= 0.03) sr = 2;
    if(_qber > 0.03 && _qber <= 0.04) sr = 3;
    if(_qber > 0.04 && _qber <= 0.05) sr = 4;
    if(_qber > 0.05 && _qber <= 0.06) sr = 5;
    if(_qber > 0.06 && _qber <= 0.07) sr = 6;
    if(_qber > 0.07 && _qber <= 0.08) sr = 7;
    if(_qber > 0.08 && _qber <= 0.09) sr = 8;
    if(_qber > 0.09 && _qber <= 0.1)  sr = 9;
    if(_qber > 0.1)                   sr = 10;

    LDPCDecode decode(memory[sr], channelinfo, decodingmethodinfo);

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

void LibLDPC::init(int seed)
{
    if(!memory.empty()) return;

    using namespace std;

    cout << "Initialising LDPC..." << endl;
    for(auto r : speeds)
    {
        cout << "\tSpeed " << r  << "..." << endl;
        int s = int(constSize/r)+1;
        memory.push_back(
            LDPCCode(s - constSize,
                s,
                seed,
                LDPCMakeLDPC::Evenboth,
                "5x2/4x3/1x7",
                true));
    }
}

#endif //! LIBLDPC_CPP
