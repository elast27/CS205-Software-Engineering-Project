#ifndef FIRSTRESPONDER_DB_H
#define FIRSTRESPONDER_DB_H

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
 * @brief The FirstResponder_DB class is the database for FirstResponder
 */
class FirstResponder_DB
{
public:
    /**
     * @brief FirstResponder_DB creates the sqlite file and open it
     */
    FirstResponder_DB();
    ~FirstResponder_DB();

    /**
     * @brief create_table  creates the table with schema
     * @return              true if the table has been created successfully, false otherwise
     */
    bool create_table();

    /**
     * @brief insert                 inserts a row into the table
     * @param FirstResponder_id      the unique int number for a particular FirstResponder
     * @param FirstResponder_name    the English desciption of the FirstResponder
     * @param solution      the English desciption of solution for the FirstResponder
     * @return              true if the row has been successfully inserted, false otherwise
     */
    bool insert(int FirstResponder_id, const QString& occupation, bool isActive);

    /**
     * @brief print         print the content of the database on the terminal
     */
    void print();

    /**
     * @brief if_exists                 check whether a FirstResponder with the given name exists in the database
     * @param FirstResponder_name       the English name of the FirstResponder
     * @return                          true if the FirstResponder has been found, false otherwise
     */
    bool if_exists(int FirstResponder_id);

    /**
     * @brief remove_FirstResponder     remove the FirstResponder in the database with the given name
     * @param FirstResponder_name       the English name of the FirstResponder
     * @return                          true if the FirstResponder has been removed successfully, false otherwise
     */
    bool remove_FirstResponder(int FirstResponder_id);

    //a database connection with qsqlite driver
    QSqlDatabase FirstResponder_db;

    //the database executer
    QSqlQuery *query;
};

#endif // FirstResponder_DB_H
