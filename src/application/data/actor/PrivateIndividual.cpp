#include "PrivateIndividual.h"

PrivateIndividual::PrivateIndividual(Catalog* catalog)
    : _userScore(0), _catalog(catalog) {

}

PrivateIndividual::PrivateIndividual(const string & email,const string & password)
    :Actor(email,password)
{

}

double PrivateIndividual::getUserScore() const
{
    return this->_userScore;
}

Sensor* PrivateIndividual::getSensor() const
{
    return this->_sensor;
}

void PrivateIndividual::setUserScore(const double & userScore)
{
    this->_userScore = userScore;
}

void PrivateIndividual::setSensor(const Sensor* & sensor)
{
    *(this->_sensor) = *(sensor);
}

istream & operator>>(istream &in, PrivateIndividual & privateIndividual) {
    string userId, sensorId, tmp;
    getline(in, userId, ';');
    getline(in, sensorId, ';');
    getline(in, tmp, '\n');

    sensorId = sensorId.substr(6, sensorId.size() - 6);

    privateIndividual._login = userId;
    privateIndividual._sensor = privateIndividual._catalog->getSensorById(stoi(sensorId));

    return in;
}
