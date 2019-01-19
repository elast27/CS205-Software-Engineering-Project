#include "controller_db.h"
#include "person_db.h"
#include "firstresponder_db.h"


int main()
{

    /*
    QString a("EarthQuake");
    QString b("Run");

    QString c("Fire");
    QString d("Water");
    Controller_DB contro;
    contro.create_table();
    contro.insert(1, a, b);
    contro.insert(2, c, d);
    contro.print();
    */


    QString p1("Cam");
    QString p2("Eric");
    Person_DB person;

    person.create_table();
    person.insert(1,p1, 19, 10.1, 20.2);
    person.insert(2, p2,18, 10.2, 20.3);

    //person.remove_person(p2);
    person.print();


    /*
    QString o1("FireFighter");
    FirstResponder_DB fr;
    fr.create_table();

    fr.insert(1, o1, false);
    fr.print();
    */


    /*


    std::cout << "--------------------------------------" << std::endl;

    QSqlQuery query(m_db);
    int numRows;
    query.exec("select title, cost from movies where cost < 100 and cost > 10;");

    while (query.next()) {
        QString title = query.value(0).toString();
        int         cost  = query.value(1).toInt();
        std::cout << title.toStdString()
                  << "  "
                  << cost
                  << std::endl;
    }

    query.last();
    numRows = query.at() + 1;

    std::cout << "Rows found : " << numRows << std::endl;

    std::cout << "--------------------------------------" << std::endl;

    query.prepare("select title, cost from movies where cost < :upper and cost > :lower;");
    query.bindValue(":upper", 100);
    query.bindValue(":lower", 50);
    query.exec();

    while (query.next()) {
        QString title = query.value(0).toString();
        int         cost  = query.value(1).toInt();
        std::cout << title.toStdString()
                  << "  "
                  << cost
                  << std::endl;
    }

    query.last();
    numRows = query.at() + 1;

    std::cout << "Rows found : " << numRows << std::endl;
*/
}
