#ifndef COORDINATES_H
#define COORDINATES_H


class Coordinates
{
protected:
    double _latitude;
    double _longitude;
public:
    Coordinates(const double & latitude, const double & longitude);
    double getLatitude() const;
    double getLongitude() const;
    double distanceTo(const Coordinates & coordinates);
};

#endif // COORDINATES_H
