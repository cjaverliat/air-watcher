#include "Coordinates.h"

Coordinates::Coordinates(const double &latitude /* = 0 */, const double &longitude /* = 0 */)
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
