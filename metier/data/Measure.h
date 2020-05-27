#ifndef MEASURE_H
#define MEASURE_H

#include <time.h>
#include "Sensor.h"

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
    Sensor _sensor;

public:
    Measure();
    Measure(const unsigned int &id, const double &valueO3, const double &valueSO2, const double &valueNO2, const double &valuePM10, const time_t &date, const Sensor &sensor);
    double getValueO3() const;
    double getValueSO2() const;
    double getValueNO2() const;
    double getValuePM10() const;
    time_t getDate() const;
    Sensor getSensor() const;
    unsigned int getId() const;
};

#endif // MEASURE_H
