#include <QString>
#include <QtTest>
#include "../publicQML/person.h"

/**
 * @brief QT test for Person class
 */
class Test_personTest : public QObject
{
    Q_OBJECT

public:
    Test_personTest();

private Q_SLOTS:
    void testCase1();
};

Test_personTest::Test_personTest()
{
}

void Test_personTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(Test_personTest)

#include "tst_test_persontest.moc"
