#include <QString>
#include <QtTest>
#include "../publicQML/person.h"
#include "../publicQML/citizen.h"
#include "../toolsQML/locationfinder.h"
#include <qdebug.h>

/**
 * @brief QT unit test for public will unit test the person and citizen classes
 */
class Test_publicTest : public QObject
{
    Q_OBJECT

public:
    Test_publicTest();

private Q_SLOTS:
    void testInitialize();
    void testLocation();
    void testSetters();
    void testPrints();
    void testCitizenDistress();
    void testCitizenSaved();
    void testInitializeCitizen();
    void testCitizenPriority();
};

Test_publicTest::Test_publicTest()
{
}

/**
 * @brief Test_publicTest::testInitialize tests that a person can correctly be initialized into memory
 */
void Test_publicTest::testInitialize() //all pass
{
    Person *p = new Person();
    p->initialize(12345, "Cameron", 19);
    QCOMPARE(p->name(), "Cameron");
    QCOMPARE(p->ID(), (unsigned int)12345);
    QCOMPARE(p->age(), (unsigned int)19);
    QCOMPARE(p->active(), false);
    QCOMPARE(p->get_person_count(), 0);
    QCOMPARE(Person::id_cnt, 1);
    delete p;
}

/**
 * @brief Test_publicTest::testLocation tests that a person's location can be validly recorded
 */
void Test_publicTest::testLocation() //FAILURE-LOOK INTO LOCATION FINDER IN TOOLS
{
    Person *p = new Person();
    p->initialize(12345, "Cameron", 19);
    qDebug() << "Printing person p's latitutde and longitude: " << p->latitude() << " " << p->longitude();
    delete p;

}

/**
 * @brief Test_publicTest::testSetters tests setting the different variables
 */
void Test_publicTest::testSetters() //pass
{
    Person *p = new Person();
    p->initialize(12345, "Cameron", 19);
    p->setActive(true);
    p->setID(65432);
    p->setName("Alex");
    p->setAge(25);

    QCOMPARE(p->name(), "Alex");
    QCOMPARE(p->ID(), (unsigned int)65432);
    QCOMPARE(p->age(), (unsigned int)25);
    QCOMPARE(p->active(), true);
    delete p;

}

/**
 * @brief Test_publicTest::testPrints tests the format of person to the qDebug output stream
 */
void Test_publicTest::testPrints()
{
    Person *p = new Person();
    p->initialize(12345, "Cameron", 19);
    qDebug () << p;
    delete p;
}

void Test_publicTest::testInitializeCitizen()
{
    Citizen *c = new Citizen(new Person());
    c->initialize(44, "Citizen Bob", 32);
    QCOMPARE(c->active(), false);
    QCOMPARE(c->priority(), Citizen::Priority::VeryLow);
    QCOMPARE(c->ID(), (unsigned int)44);
    QCOMPARE(c->age(), (unsigned int) 32);
    QCOMPARE(c->name(), "Citizen Bob");
    delete c;

}

/**
 * @brief Test_publicTest::testCitizenDistress tests if a citizen's activity status can correctly change to true
 */
void Test_publicTest::testCitizenDistress() //PASS
{
    Citizen *c = new Citizen( new Person());
    c->initialize(43, "Laura", 22);
    QCOMPARE(c->active(), false);
    c->send_distress_message();
    QCOMPARE(c->active(), true);
    delete c;

}

/**
 * @brief Test_publicTesttestCitizenSaved tests if a citizen's activity status can correctly change to false
 */
void Test_publicTest::testCitizenSaved() //PASS
{
    Citizen *c = new Citizen( new Person());
    c->initialize(43, "Laura", 22);
    QCOMPARE(c->active(), false);
    c->send_distress_message();
    QCOMPARE(c->active(), true);
    c->get_saved();
    QCOMPARE(c->active(), false);
    delete c;

}

void Test_publicTest::testCitizenPriority() //PASS
{
    Citizen *c = new Citizen(new Person());
    c->initialize(53, "Joe", 21);
    QCOMPARE(c->priority(), Citizen::Priority::VeryLow);
    c->setPriority(Citizen::Priority::High);
    QCOMPARE(c->priority(), Citizen::Priority::High);
    c->setPriority(Citizen::Priority::VeryHigh);
    QCOMPARE(c->priority(), Citizen::Priority::VeryHigh);
    c->setPriority(Citizen::Priority::VeryLow);
    QCOMPARE(c->priority(), Citizen::Priority::VeryLow);

}

QTEST_APPLESS_MAIN(Test_publicTest)

#include "tst_test_publictest.moc"
