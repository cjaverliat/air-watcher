#ifndef SENSOR_H
#define SENSOR_H

#include<iostream>
#include<string.h>
#include"Coordinates.h"

using namespace std;

class Sensor
{
protected:
    unsigned int _id;
    string _description;
    Coordinates _coordinates;
public:
    Sensor(const unsigned int & id, const string & description, const Coordinates & coordinates);
    string getDescription() const;
    void setDescription(const string &value);
    unsigned int getId() const;
    Coordinates getCoordinates() const;
    void setCoordinates(const Coordinates &coordinates);
};

#endif // SENSOR_H
