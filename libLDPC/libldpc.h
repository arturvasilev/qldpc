#ifndef LIBLDPC_H
#define LIBLDPC_H


#include "../LDPC-4Qt/ldpc4qt.h"
#include <fstream>
#include <QByteArray>
#include <vector>
#include <QCoreApplication>
#include <QtWidgets/QApplication>

namespace LibLDPC
{

    /*
     * @brief Возвращает LDPC-код для исправления ошибок на приёмной стороне
     * 
     * @param vkey      Отправляемое сообщение
     * @param _qber     Доля ошибочных бит
     * @param seed      Зерно для ПСП. Должен быть одинаковым для энкодера и декодера
     * 
     * @return LDPC-код
     */
    std::vector<bool> Encoder(
        std::vector<bool> &vkey,
        const double _qber,
        int seed);
    
    /*
     * @brief Возвращает сообщение, избавленное от ошибок
     * 
     * @param vkey      Сообщение с ошибочными битами
     * @param ldpcCode  LDPC-код от энкодера
     * @param _qber     Доля ошибочных бит
     * @param seed      Зерно для ПСП. Должен быть одинаковым для энкодера и декодера
     * 
     * @return LDPC-код
     */
    std::vector<bool> Decoder(
        std::vector<bool> &vkey, 
        std::vector<bool> &ldpcCode,
        const float _qber,
        int seed);
};
#endif // LIBLDPC1_H
