#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <QObject>
#include <QWidget>
#include <QDebug>
#include <QtCore>
#include "../toolsQML/locationfinder.h"
#include "../toolsQML/fileio.h"

/**
 * @brief The Person class represents a stakeholder in the system. It is the baseclass for all other person-related objects via is-a relationship
 */
class Person : public QObject
{
    Q_OBJECT //macro for moc

    //******************************PROPERTIES***************************//
    Q_PROPERTY(unsigned int ID READ ID WRITE setID NOTIFY IDChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(double latitude READ latitude WRITE setLatitude NOTIFY latitudeChanged)
    Q_PROPERTY(double longitude READ longitude WRITE setLongitude NOTIFY longitudeChanged)
    Q_PROPERTY(unsigned int age READ age WRITE setAge NOTIFY ageChanged)
    Q_PROPERTY(bool active READ active WRITE setActive NOTIFY activeChanged)
   // Q_PROPERTY(QGeoCoordinate coordinate READ coordinate WRITE setcoordinate NOTIFY coordinateChanged)

public:

    explicit Person(QObject *parent = 0);

    virtual ~Person();

    static int id_cnt; //class counter


    //*************************PUBLIC METHODS***********************///

    /**
     * @brief initialize initializes fields for this person
     * @param id person's id
     * @param name person's name
     * @param age  person's age
     */
    Q_INVOKABLE void initialize(unsigned int id, QString name, unsigned int age);

    /**
     * @brief ID returns this person's ID
     * @return this person's ID
     */
   unsigned int ID() const;

    /**
     * @brief name returns this person's name
     * @return this person's name
     */
    QString name() const;

    /**
     * @brief latitude returns this person's latitude
     * @return this person's latitude as a double
     */

    double latitude() const;

    /**
     * @brief longitude returns this person's longitude
     * @return this person's longitude as a double
     */
     double longitude() const;


    /**
     * @brief age returns this person's age
     * @return this person's age
     */
    unsigned int age() const;

    /**
     * @brief active returns whether this person is currently active (needs help if public, on duty if first responder or command center member)
     * @return this person's activity status
     */
     bool active() const;

    /**
     * @brief coordinate returns this person's QGeoCoordinate
     * @return this person's QGeoCoordinate
     */
     QGeoCoordinate coordinate() const;

  /**
   * @brief operator << overloads << for stream output
   * @param out the output stream
   * @param p a person object
   * @return the output stream
   */
   friend QDataStream& operator << (QDataStream& out, Person& p)
   {
      out << "Name: " << p.m_name << "\n"
          << "ID: "  << p.m_ID  << "\n"
          << "lat: "  << p.m_latitude << "\n"
          << "long: " << p.m_longitude << "\n"
          << "age: " << p.m_age      << "\n"
          << "Active: " << p.m_active << "\n";
      return out;
   }

   /**
    * @brief get_person_count returns the running person count
    * @return this.person_cnt
    */
   int get_person_count() const;



protected:

    unsigned int m_ID;
    QString m_name;
    mutable double m_latitude;
    mutable double m_longitude;
    unsigned int m_age;
    bool m_active;     //is the person in distress or on the field?
    int person_cnt;    //person-specific object ID counter
    LocationFinder *location_finder;  //location finder for this person

signals:
    void IDChanged(int id);
    void nameChanged(QString name);
    void latitudeChanged(double lat);
    void longitudeChanged(double longitude);
    void ageChanged(unsigned int age);
    void activeChanged(bool active);


public slots:
    void setID(unsigned int id);
    void setName(QString name);
    void setLatitude(double lat);
    void setLongitude(double longitude);
    void setAge(unsigned int age);
    void setActive(bool active);

};

#endif // PERSON_H
