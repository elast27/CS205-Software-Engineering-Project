#include <QString>
#include <QtTest>
#include "../command_center/controller.h"
#include "../command_center/director.h"
#include "../command_center/erp.h"

/**
 * @brief QT unit test for command_center
 */
class Test_command_centerTest : public QObject
{
    Q_OBJECT

public:
    Test_command_centerTest();

private Q_SLOTS:
    void testCase1();
};

Test_command_centerTest::Test_command_centerTest()
{
}

void Test_command_centerTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(Test_command_centerTest)

#include "tst_test_command_centertest.moc"
