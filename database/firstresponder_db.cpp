#include "firstresponder_db.h"


FirstResponder_DB::FirstResponder_DB()
{
    //create a database connection with qsqlite driver
    FirstResponder_db = QSqlDatabase::addDatabase("QSQLITE");

    QString path("../FirstResponder_db.sqlite");

    //set database name
    FirstResponder_db.setDatabaseName(path);

    //open the database
    if(!FirstResponder_db.open()){
        qDebug() << "fail to open the database connection";
    }else{
        qDebug() << "connection OK!";
    }

    //execute the database
    query = new QSqlQuery(FirstResponder_db);

}


bool FirstResponder_DB::create_table(){
    bool pass = false;
    if(
    query->exec("CREATE TABLE IF NOT EXISTS FirstResponder(FirstResponder_id    INT NOT NULL UNIQUE,"
                                                      "occupation    CHAR NOT NULL,"
                                                      "isActive      BOOL NOT NULL)"
                                                      )){
        pass = true;
        qDebug() << "create_table OK";
    }else{
        qDebug() << "fail to create table" << query->lastError();
    }
    return pass;
}


bool FirstResponder_DB::insert(int FirstResponder_id, const QString &occupation, bool isActive){
    bool pass = false;
    query->prepare("INSERT INTO FirstResponder(FirstResponder_id, occupation, isActive) "
                   "VALUES(:FirstResponder_id, :occupation, :isActive)");
    query->bindValue(":FirstResponder_id", FirstResponder_id);
    query->bindValue(":occupation", occupation);
    query->bindValue(":isActive", isActive);
    if(query->exec()){
        pass = true;
        qDebug() << "insert OK";
    }else{
        qDebug() << "fail to insert" << query->lastError();
    }
    return pass;
}

/* Print the content of whole database
 * FirstResponder_id, occupation, isActive
 * int,               QString,    bool
 */
void FirstResponder_DB::print(){
    QSqlQuery q("SELECT * FROM FirstResponder");

    while(q.next()){

        int id             = q.value(0).toInt();
        QString occupation = q.value(1).toString();
        bool isActive      = q.value(2).toBool();

        std::cout<<id
                << '\t'
                <<occupation.toStdString()
               << '\t'
               <<isActive
              <<std::endl;

    }
}

//Return true if such FirstResponder exists in the table
bool FirstResponder_DB::if_exists(int FirstResponder_id){
    query->prepare("SELECT FirstResponder_id FROM FirstResponder WHERE FirstResponder_id = (:FirstResponder_id)");
    query->bindValue(":FirstResponder_id", FirstResponder_id);
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

/* Remove the FirstResponder in the table with the given FirstResponder_id
 * Return true if the FirstResponder has been successfully removed
 */
bool FirstResponder_DB::remove_FirstResponder(int FirstResponder_id){
    if(if_exists(FirstResponder_id)){
        query->prepare("DELETE FROM FirstResponder WHERE FirstResponder_id = (:FirstResponder_id)");
        query->bindValue(":FirstResponder_id", FirstResponder_id);
        if(query->exec()){
            qDebug() << "remove_FirstResponder OK";
            return true;
        }else{
            qDebug() << "fail to remove_FirstResponder" << query->lastError();
            return false;
        }
    }else{
        std::cerr << "No such FirstResponder in the table" << std::endl;
        return false;
    }

}



/* Delete the content of the table
 * Drop table
 * Close the database
 */
FirstResponder_DB::~FirstResponder_DB(){
    query->exec("DELETE FROM FirstResponder_db");
    query->exec("DROP TABLE IF EXISTS FirstResponder");
    FirstResponder_db.close();
}






