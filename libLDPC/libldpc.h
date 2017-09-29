//#ifndef LIBLDPC_H
//#define LIBLDPC_H


#include "../LDPC-4Qt/ldpc4qt.h"
#include <fstream>
#include <QByteArray>
#include <vector>
#include <QCoreApplication>
#include<QtWidgets/QApplication>

//class LibLDPC
//{
  //  public:
    //LibLDPC();

    std::vector<bool> Encoder( std::vector<bool> &vkey, const double _qber, int seed);
    std::vector<bool> Decoder(std::vector<bool> &vkey, std::vector<bool> &ldpcCode, const float _qber, QString filename, int seed);
//};
//#endif // LIBLDPC1_H
