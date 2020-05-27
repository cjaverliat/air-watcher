#ifndef PRIVATEINDIVIDUAL_H
#define PRIVATEINDIVIDUAL_H

#include"Actor.h"
#include"../data/Sensor.h"

class PrivateIndividual : public Actor
{
protected:
    double _userScore;
    Sensor* _sensor; //faire un setter
public:
    PrivateIndividual(const string & login,const string & password);
    double getUserScore() const;
    Sensor getSensor() const;
    void setUserScorse(const double & userScore);
    void setSensor(const Sensor* & sensor);
};

#endif // PRIVATEINDIVIDUAL_H
