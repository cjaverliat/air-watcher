#ifndef PRIVATEINDIVIDUAL_H
#define PRIVATEINDIVIDUAL_H

#include"Actor.h"
#include"../data/Sensor.h"
#include"../data/Catalog.h"

class Catalog;

class PrivateIndividual : public Actor
{
protected:
    double _userScore;
    Sensor* _sensor; //faire un setter
    Catalog* _catalog;
public:
    PrivateIndividual(Catalog* catalog);
    PrivateIndividual(const string & login,const string & password);
    double getUserScore() const;
    Sensor* getSensor() const;
    void setUserScorse(const double & userScore);
    void setSensor(const Sensor* & sensor);
    friend istream & operator >> (istream & in, PrivateIndividual & privateIndividual);
};

#endif // PRIVATEINDIVIDUAL_H
