#ifndef PERSON_DB_H
#define PERSON_DB_H

#include <iostream>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>
#include <QSqlError>
#include <QGeoPositionInfoSource>
#include <string>

/**
 * @brief The Person_DB class is the database for Person
 */
class Person_DB
{
public:
    /**
     * @brief Person_DB creates the sqlite file and open it
     */
    Person_DB();
    ~Person_DB();

    /**
     * @brief create_table  creates the table with schema
     * @return              true if the table has been created successfully, false otherwise
     */
    bool create_table();

    /**
     * @brief insert        inserts a row into the table
     * @param person_id     the unique int number for a particular person
     * @param person_name   the English desciption of the person
     * @param age           the age of the person
     * @param lagitude      the lagitude for this person
     * @param latitude      the latitude for this person
     * @return              true if the row has been successfully inserted, false otherwise
     */
    bool insert(int person_id, const QString& person_name, int age, double lagitude, double latitude);

    /**
     * @brief print         print the content of the database on the terminal
     */
    void print();

    /**
     * @brief if_exists     check whether a person with the given name exists in the database
     * @param person_name   the English name of the person
     * @return              true if the person has been found, false otherwise
     */
    bool if_exists(const QString& person_name);

    /**
     * @brief remove_person  remove the person in the database with the given name
     * @param person_name    the English name of the person
     * @return               true if the person has been removed successfully, false otherwise
     */
    bool remove_person(const QString& person_name);

    //a database connection with qsqlite driver
    QSqlDatabase person_db;

    //the database executer
    QSqlQuery *query;
};

#endif // Person_DB_H
