#include "person_db.h"


Person_DB::Person_DB()
{
    //create a database connection with qsqlite driver
    person_db = QSqlDatabase::addDatabase("QSQLITE");

    QString path("../person_db.sqlite");

    //set database name
    person_db.setDatabaseName(path);

    //open the database
    if(!person_db.open()){
        qDebug() << "fail to open the database connection";
    }else{
        qDebug() << "connection OK!";
    }

    //execute the database
    query = new QSqlQuery(person_db);

}


bool Person_DB::create_table(){
    bool pass = false;
    if(
    query->exec("CREATE TABLE IF NOT EXISTS person(person_id    INT NOT NULL UNIQUE,"
                                                      "person_name  CHAR NOT NULL,"
                                                      "person_age    INT NOT NULL,"
                                                      "lagitude      DOUBLE NOT NULL,"
                                                      "latitude      DOUBLE NOT NULL)"
                                                      )){
        pass = true;
        qDebug() << "create_table OK";
    }else{
        qDebug() << "fail to create table" << query->lastError();
    }
    return pass;
}


bool Person_DB::insert(int person_id, const QString &person_name, int age, double lagitude, double latitude){
    bool pass = false;
    query->prepare("INSERT INTO person(person_id, person_name, person_age, lagitude, latitude) "
                   "VALUES(:person_id, :person_name, :age, :lagitude, :latitude)");
    query->bindValue(":person_id", person_id);
    query->bindValue(":person_name", person_name);
    query->bindValue(":age", age);
    query->bindValue(":lagitude", lagitude);
    query->bindValue(":latitude", latitude);
    if(query->exec()){
        pass = true;
        qDebug() << "insert OK";
    }else{
        qDebug() << "fail to insert" << query->lastError();
    }
    return pass;
}

/* Print the content of whole database
 * person_id, person_name, age, lagitude, latitude
 * int,       QString,     int, double,   double
 */
void Person_DB::print(){
    QSqlQuery q("SELECT * FROM person");

    while(q.next()){

        int id          = q.value(0).toInt();
        QString name    = q.value(1).toString();
        int age         = q.value(2).toInt();
        double lagitude = q.value(3).toDouble();
        double latitude = q.value(4).toDouble();

        std::cout<<id
                << '\t'
                <<name.toStdString()
               << '\t'
               <<age
               <<'\t'
              <<lagitude
             <<'\t'
            <<latitude
              <<std::endl;

    }
}

//Return true if such person exists in the table
bool Person_DB::if_exists(const QString& person_name){
    query->prepare("SELECT person_name FROM person WHERE person_name = (:person_name)");
    query->bindValue(":person_name", person_name);
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

/* Remove the person in the table with the given person_name
 * Return true if the person has been successfully removed
 */
bool Person_DB::remove_person(const QString& person_name){
    if(if_exists(person_name)){
        query->prepare("DELETE FROM person WHERE person_name = (:person_name)");
        query->bindValue(":person_name", person_name);
        if(query->exec()){
            qDebug() << "remove_person OK";
            return true;
        }else{
            qDebug() << "fail to remove_person" << query->lastError();
            return false;
        }
    }else{
        std::cerr << "No such person in the table" << std::endl;
        return false;
    }

}



/* Delete the content of the table
 * Drop table
 * Close the database
 */
Person_DB::~Person_DB(){
    query->exec("DELETE FROM person_db");
    query->exec("DROP TABLE IF EXISTS person");
    person_db.close();
}






