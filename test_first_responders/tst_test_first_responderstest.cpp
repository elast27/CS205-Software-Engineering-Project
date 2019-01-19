#include <QString>
#include <QtTest>
#include "../first_respondersQML/ems.h"
#include "../first_respondersQML/firefighter.h"
#include "../first_respondersQML/police.h"
#include "../first_respondersQML/swat.h"

/**
 * @brief QT unit test for First Responders
 */
class Test_first_respondersTest : public QObject
{
    Q_OBJECT

public:
    Test_first_respondersTest();

private Q_SLOTS:
    void testCase1();
};

Test_first_respondersTest::Test_first_respondersTest()
{
}

void Test_first_respondersTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(Test_first_respondersTest)

#include "tst_test_first_responderstest.moc"
