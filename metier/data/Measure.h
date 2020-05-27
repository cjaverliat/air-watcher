#ifndef MEASURE_H
#define MEASURE_H

#include<time.h>
#include"Sensor.h"

using namespace std;

class Measure
{
protected:
    unsigned int _id;
    double _valeurO3;
    double _valeurS02;
    double _valeurNO2;
    double _valeurPM10;
    time_t _date;
    Sensor _sensor;
public:
    Measure();
    Measure(const unsigned int & id, const double & valeurO3, const double & valeurSO2, const double & valeurNO2, const double & valeurPM10, const time_t & date, const Sensor & sensor);
    double getValeurO3() const;
    double getValeurS02() const;
    double getValeurNO2() const;
    double getValeurPM10() const;
    time_t getDate() const;
    Sensor getSensor() const;
    unsigned int getId() const;
};

#endif // MEASURE_H
