#include <utils/Utils.h>
#include "Coordinates.h"

Coordinates::Coordinates(const double &latitude /* = 0 */, const double &longitude /* = 0 */)
    :_latitude(latitude),_longitude(longitude)
{
    _latitudeRadians = toRadians(latitude);
    _longitudeRadians = toRadians(longitude);
}

double Coordinates::getLongitude() const
{
    return _longitude;
}

double Coordinates::getLatitude() const
{
    return _latitude;
}

double Coordinates::getLongitudeInRadians() const
{
    return _longitudeRadians;
}

double Coordinates::getLatitudeInRadians() const
{
    return _latitudeRadians;
}
