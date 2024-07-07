#include <QtTest>
#include "tst_testcalculating.h"

void TestCalculating::init()
{
    mCalc.SetA(A0);
    mCalc.SetB(B0);
}

void TestCalculating::testSum_data()
{
    QTest::addColumn<int>("a");
    QTest::addColumn<int>("b");
    QTest::addColumn<int>("result");

    QTest::newRow("all 0") << 0 << 0 << 0;
    QTest::newRow("10 and 10") << 10 << 10 << 20;
    QTest::newRow("20 and 4") << 20 << 4 << 24;
}

void TestCalculating::testSum()
{
    QFETCH(int, a);
    QFETCH(int, b);
    QFETCH(int, result);

    mCalc.SetA(a);
    mCalc.SetB(b);
    QCOMPARE(mCalc.Sum(), result);
}

void TestCalculating::testDiv()
{
    const int A = 20;
    const int B = 10;
    mCalc.SetA(A);
    mCalc.SetB(B);
    QCOMPARE(mCalc.Div(), A / B);

    // QSKIP("Are you sure we need continue?");
    QEXPECT_FAIL("", "we must avoid dividing on 0", Abort);
    QVERIFY(mCalc.isNull());

    QCOMPARE(mCalc.Div(), A0 / B0);
}

QTEST_APPLESS_MAIN(TestCalculating)
//#include "TestCalculating.moc"
