#ifndef COORDINATES_H
#define COORDINATES_H


class Coordinates
{
protected:
    double _latitude;
    double _longitude;
public:
    Coordinates(const double & latitude = 0, const double & longitude = 0);
    double getLatitude() const;
    double getLongitude() const;
    double distanceTo(const Coordinates & coordinates);
};

#endif // COORDINATES_H
