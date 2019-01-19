#include "controller_db.h"


Controller_DB::Controller_DB()
{
    //create a database connection with qsqlite driver
    controller_db = QSqlDatabase::addDatabase("QSQLITE");

    QString path("../controller_db.sqlite");

    //set database name
    controller_db.setDatabaseName(path);

    //open the database
    if(!controller_db.open()){
        qDebug() << "fail to open the database connection";
    }else{
        qDebug() << "connection OK!";
    }

    //execute the database
    query = new QSqlQuery(controller_db);

}


bool Controller_DB::create_table(){
    bool pass = false;
    if(
    query->exec("CREATE TABLE IF NOT EXISTS controller(event_id    INT NOT NULL UNIQUE,"
                                                      "event_name  CHAR NOT NULL,"
                                                      "solution    CHAR NOT NULL)")){
        pass = true;
        qDebug() << "create_table OK";
    }else{
        qDebug() << "fail to create table" << query->lastError();
    }

    return pass;
}


bool Controller_DB::insert(int event_id, const QString &event_name, const QString &solution){
    bool pass = false;
    query->prepare("INSERT INTO controller(event_id, event_name, solution) VALUES(:event_id, :event_name, :solution)");
    query->bindValue(":event_id", event_id);
    query->bindValue(":event_name", event_name);
    query->bindValue(":solution", solution);
    if(query->exec()){
        pass = true;
        qDebug() << "insert OK";
    }else{
        qDebug() << "fail to insert" << query->lastError();
    }
    return pass;
}

/* Print the content of whole database
 * event_id, event_name, solution
 * int,      QString,    QString
 */
void Controller_DB::print(){
    QSqlQuery q("SELECT * FROM controller");

    while(q.next()){

        int id          = q.value(0).toInt();
        QString name    = q.value(1).toString();
        QString sol     = q.value(2).toString();

        std::cout<<id
                << '\t'
                <<name.toStdString()
               << '\t'
               <<sol.toStdString()
              <<std::endl;

    }
}

//Return true if such event exists in the table
bool Controller_DB::if_exists(const QString& event_name){
    query->prepare("SELECT event_name FROM controller WHERE event_name = (:event_name)");
    query->bindValue(":event_name", event_name);
    if(query->exec()){
       qDebug() << "if_exists OK";
       if(query->next()){
           return true;
       }
    }else{
        qDebug() << "if_exists failed" << query->lastError();
    }

    return false;
}

/* Remove the event in the table with the given event_name
 * Return true if the event has been successfully removed
 */
bool Controller_DB::remove_event(const QString& event_name){
    if(if_exists(event_name)){
        query->prepare("DELETE FROM controller WHERE event_name = (:event_name)");
        query->bindValue(":event_name", event_name);
        if(query->exec()){
            qDebug() << "remove_event OK";
            return true;
        }else{
            qDebug() << "fail to remove_event" << query->lastError();
            return false;
        }
    }else{
        std::cerr << "No such event in the table" << std::endl;
        return false;
    }

}



/* Delete the content of the table
 * Drop table
 * Close the database
 */
Controller_DB::~Controller_DB(){
    query->exec("DELETE FROM controller_db");
    query->exec("DROP TABLE IF EXISTS controller");
    controller_db.close();
}






