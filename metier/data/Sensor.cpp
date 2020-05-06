#include "sensor.h"

Sensor::Sensor(const unsigned int &id, const string &description, const Coordinates &coordinates)
    :_id(id),_description(description),_coordinates(coordinates)
{

}

Coordinates Sensor::getCoordinates() const
{
    return _coordinates;
}

void Sensor::setCoordinates(const Coordinates &coordinates)
{
    _coordinates = coordinates;
}

unsigned int Sensor::getId() const
{
    return _id;
}

string Sensor::getDescription() const
{
    return _description;
}

void Sensor::setDescription(const string &value)
{
    _description = value;
}
