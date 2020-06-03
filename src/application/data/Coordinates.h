#ifndef COORDINATES_H
#define COORDINATES_H


class Coordinates
{
protected:
    double _latitude;
    double _longitude;
    double _latitudeRadians;
    double _longitudeRadians;
public:
    Coordinates(const double & latitude = 0, const double & longitude = 0);
    double getLatitude() const;
    double getLongitude() const;
    double getLatitudeInRadians() const;
    double getLongitudeInRadians() const;
};

#endif // COORDINATES_H
