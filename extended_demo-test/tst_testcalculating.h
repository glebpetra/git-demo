#ifndef TST_TESTCALCULATING_H
#define TST_TESTCALCULATING_H

#include "calculator.h"

#include <QtTest>

class TestCalculating : public QObject
{
    Q_OBJECT

// public:
//     TestCalculating();
//     ~TestCalculating();

private slots:
    void init();
    void testSum();
    void testSum_data();
    void testDiv();

private:
    Calculator mCalc;
    const int A0 = 0;
    const int B0 = 0;
};



#endif // TST_TESTCALCULATING_H
