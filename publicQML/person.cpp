#include "../publicQML/person.h"

int Person::id_cnt = 0;

Person::Person(QObject *parent) : QObject(parent)
{
    this->location_finder = new LocationFinder();
    this->m_active   = false;                    //set initial activity to false, the idea is that a pushButton will send a signal to change the activity status of a citizen, or a login for other members
    this->m_latitude = location_finder->get_coordinate().latitude();
    this->m_longitude = location_finder->get_coordinate().longitude();
    this->person_cnt = id_cnt++;
}

Person::~Person()
{

}

void Person::initialize(unsigned int id, QString name, unsigned int age)
{
    this->m_ID = id;
    this->m_name = name;
    this->m_age = age;
}

unsigned int Person::ID() const {
    return m_ID;
}

QString Person::name() const {
    return this->m_name;
}

double Person::latitude() const {
    m_latitude = location_finder->get_coordinate().latitude(); //update m_latitude so that it concurrently updates with the connection in location finder
    return m_latitude;
}

double Person::longitude() const {
    m_longitude = location_finder->get_coordinate().longitude(); //update m_longitude so that it concurrently updates with the connection in location finder
    return m_longitude;
}

unsigned int Person::age() const {
    return m_age;
}

int Person::get_person_count() const
{
    return person_cnt;
}

bool Person::active() const{
    return m_active;
}

void Person::setActive(bool active)
{
    if (active != m_active) {
           m_active = active;
           emit activeChanged(active);
       }

}

void Person::setAge(unsigned int age)
{
    if (age != m_age) {
           m_age = age;
           emit ageChanged(age);
       }


}

void Person::setID(unsigned int id)
{
    if (id != m_ID) {
           m_ID = id;
           emit IDChanged(id);
       }


}

void Person::setLatitude(double lat)
{
    if (lat != m_latitude) {
           m_latitude = lat;
           emit latitudeChanged(lat);
       }
}

void Person::setLongitude(double longitude)
{
    if (longitude != m_longitude) {
           m_longitude = longitude;
           emit longitudeChanged(longitude);
       }
}

void Person::setName(QString name)
{
    if (name != m_name) {
           m_name = name;
           emit nameChanged(name);
       }
}

QGeoCoordinate Person::coordinate() const
{
    QGeoCoordinate currentCoordinates = location_finder->get_coordinate();
    return currentCoordinates;
}

