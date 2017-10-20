#ifndef LIBLDPC_H
#define LIBLDPC_H

#include "LDPC-4Qt/ldpc4qt.h"
#include <fstream>
#include <QByteArray>
#include <vector>
#include <QCoreApplication>
#include <QtWidgets/QApplication>

namespace LibLDPC
{
    //!!! Размер ключа должен быть постоянным и быть равен 1000 (одной тысяче)
    //!!! QBER не должен превышать 0.11
    static std::vector<LDPCCode> memory;
    static std::vector<double> speeds = {0.85, 0.75, 0.65, 0.63, 0.55, 0.53, 0.52, 0.47, 0.45, 0.35, 0.30};
    static const uint constSize = 1000;
    
    void init(int seed);

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
        const double _qber,
        int seed);

    //! Диапазоны QBER
    
};

#endif // LIBLDPC_H
