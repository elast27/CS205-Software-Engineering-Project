#ifndef LOCATIONFINDER_H
#define LOCATIONFINDER_H
#include <iostream>
#include <QObject>
#include <QGeoPositionInfoSource>
#include <QDebug>

//A class that will find the location of the client via default positioning source (ie. location services for mobile, GPS for desktop via wifi)

class LocationFinder : public QObject
{
    Q_OBJECT
public:
     LocationFinder(QObject *parent = 0)
         : QObject(parent)
     {
             QGeoPositionInfoSource *source = QGeoPositionInfoSource::createDefaultSource(this);
             std::cout << source << std::endl;
             if (source) {
                 source->setUpdateInterval(500);
                 connect(source, SIGNAL(positionUpdated(QGeoPositionInfo)),this, SLOT(positionUpdated(QGeoPositionInfo)));
                 source->startUpdates();
             }
     }
     ~LocationFinder();

signals:

private slots:
     void positionUpdated(const QGeoPositionInfo &info)
         {
             qDebug() << "Position updated:" << info;
         }
};

#endif // LOCATIONFINDER_H
