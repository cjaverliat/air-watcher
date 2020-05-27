#ifndef MEASURE_H
#define MEASURE_H

#include<ctime>

#include"Sensor.h"
#include "Catalog.h"

class Catalog;

using namespace std;

class Measure
{
protected:
    unsigned int _id;
    double _valeurO3;
    double _valeurSO2;
    double _valeurNO2;
    double _valeurPM10;
    time_t _date;
    Sensor* _sensor;
    Catalog* _catalog;
public:
    Measure(Catalog* catalog);
    Measure(const unsigned int & id, const double & valeurO3, const double & valeurSO2, const double & valeurNO2, const double & valeurPM10, const time_t & date, Sensor* sensor);
    double getValueO3() const;
    double getValueSO2() const;
    double getValueNO2() const;
    double getValuePM10() const;
    time_t getDate() const;
    Sensor* getSensor() const;
    unsigned int getId() const;
    friend istream & operator >> (istream & in, Measure & measure);
};

#endif // MEASURE_H
