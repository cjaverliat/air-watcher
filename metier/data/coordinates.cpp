#include "coordinates.h"

Coordinates::Coordinates(const double &latitude, const double &longitude)
    :_latitude(latitude),_longitude(longitude)
{

}

double Coordinates::getLongitude() const
{
    return _longitude;
}

double Coordinates::getLatitude() const
{
    return _latitude;
}

double Coordinates::distanceTo(const Coordinates & coordinates)
{
    //A FAIRE
    return -1;
}
