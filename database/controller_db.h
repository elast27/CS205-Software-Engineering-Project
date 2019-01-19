#ifndef CONTROLLER_DB_H
#define CONTROLLER_DB_H

#include <iostream>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>
#include <QSqlError>
#include <string>

/**
 * @brief The Controller_DB class is the database for controller
 */
class Controller_DB
{
public:
    /**
     * @brief Controller_DB creates the sqlite file and open it
     */
    Controller_DB();
    ~Controller_DB();

    /**
     * @brief create_table  creates the table with schema
     * @return              true if the table has been created successfully, false otherwise
     */
    bool create_table();

    /**
     * @brief insert        inserts a row into the table
     * @param event_id      the unique int number for a particular event
     * @param event_name    the English desciption of the event
     * @param solution      the English desciption of solution for the event
     * @return              true if the row has been successfully inserted, false otherwise
     */
    bool insert(int event_id, const QString& event_name, const QString& solution);

    /**
     * @brief print         print the content of the database on the terminal
     */
    void print();

    /**
     * @brief if_exists     check whether a event with the given name exists in the database
     * @param event_name    the English name of the event
     * @return              true if the event has been found, false otherwise
     */
    bool if_exists(const QString& event_name);

    /**
     * @brief remove_event  remove the event in the database with the given name
     * @param event_name    the English name of the event
     * @return              true if the event has been removed successfully, false otherwise
     */
    bool remove_event(const QString& event_name);

    //a database connection with qsqlite driver
    QSqlDatabase controller_db;

    //the database executer
    QSqlQuery *query;
};

#endif // CONTROLLER_DB_H
