#include "Sensor.h"

#include "../../utils/Utils.h"

Sensor::Sensor(){

}

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

istream & operator>>(istream & in, Sensor & sensor) {
    string sensorId, latitude, longitude, description;
    getline(in, sensorId, ';');
    getline(in, latitude, ';');
    getline(in, longitude, ';');
    getline(in, description, '\n');

    sensorId = sensorId.substr(6, sensorId.size() - 6);

    sensor._id = stoi(sensorId);
    sensor._coordinates = Coordinates(stod(latitude), stod(longitude));
    sensor._description = description;

    return in;
}
