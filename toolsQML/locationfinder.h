#ifndef LOCATIONFINDER_H
#define LOCATIONFINDER_H
#include <iostream>
#include <QObject>
#include <QGeoPositionInfoSource>
#include <QDebug>

/**
 * @brief The LocationFinder class will find the location of the client via default positioning source (ie. location services for mobile, GPS for desktop via wifi)
 * @extends QObject
 */

class LocationFinder : public QObject
{
    Q_OBJECT
public:
    LocationFinder(QObject *parent = 0) : QObject(parent){
        QGeoPositionInfoSource *source = QGeoPositionInfoSource::createDefaultSource(this);
        if (source) {
            source->setUpdateInterval(500);  //setting update interval for 500ms
            connect(source, SIGNAL(positionUpdated(QGeoPositionInfo)),this, SLOT(setGeoCoordinate(QGeoPositionInfo))); //connecting to default location source
            source->startUpdates();
        }
    }

    virtual ~LocationFinder();

     /**
      * @brief coordinate returns the updated position coordinate from *source's signal. The signal feeds QGeoPositionInfo into private slot setGeoCoordinate()
      * @return a QGeoCoordinate for this LocationFinder
      */
     QGeoCoordinate get_coordinate() const
     {
         return m_coordinateInfo.coordinate();
     }

 signals:
     void positionUpdated(const QGeoPositionInfo &info);

private slots:
     void setGeoCoordinate(const QGeoPositionInfo &info);
private:
    QGeoPositionInfo m_coordinateInfo; //coordinate from the QGeoPositionInfo signal
};

#endif // LOCATIONFINDER_H
