#include <QString>
#include <QtTest>

/**
 * @brief QT unit test for Database
 */
class Test_databaseTest : public QObject
{
    Q_OBJECT

public:
    Test_databaseTest();

private Q_SLOTS:
    void testCase1();
};

Test_databaseTest::Test_databaseTest()
{
}

void Test_databaseTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(Test_databaseTest)

#include "tst_test_databasetest.moc"
