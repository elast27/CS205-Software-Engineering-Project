#include "locationfinder.h"

LocationFinder::~LocationFinder()
{

}

void LocationFinder::setGeoCoordinate(const QGeoPositionInfo &info)
{
    if (info != this->m_coordinateInfo ) {
          this->m_coordinateInfo = info;
           emit positionUpdated(info);
       }

}
