#include <QString>
#include <QtTest>
#include "../tools/locationfinder.h"

/**
 * @brief QT unit test for tools
 */
class Test_toolsTest : public QObject
{
    Q_OBJECT

public:
    Test_toolsTest();

private Q_SLOTS:
    void testCase1();
};

Test_toolsTest::Test_toolsTest()
{
}

void Test_toolsTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(Test_toolsTest)

#include "tst_test_toolstest.moc"
