#include "PrivateIndividual.h"

PrivateIndividual::PrivateIndividual(const string & email,const string & password)
    :Actor(email,password)
{

}

double PrivateIndividual::getUserScore() const
{
    return this->_userScore;
}

Sensor PrivateIndividual::getSensor() const
{
    return *(this->_sensor);
}

void PrivateIndividual::setUserScorse(const double & userScore)
{
    this->_userScore = userScore;
}

void PrivateIndividual::setSensor(const Sensor* & sensor)
{
    *(this->_sensor) = *(sensor);
}
