#include "measure.h"

Measure::Measure(const unsigned int & id, const double &valeurO3, const double &valeurSO2, const double &valeurNO2, const double &valeurPM10, const time_t &date, const Sensor & sensor)
    :_id(id),_valeurO3(valeurO3),_valeurS02(valeurSO2),_valeurNO2(valeurNO2),_valeurPM10(valeurPM10), _date(date), _sensor(sensor)
{

}

Sensor Measure::getSensor() const
{
    return _sensor;
}

double Measure::getValeurS02() const
{
    return _valeurS02;
}

double Measure::getValeurNO2() const
{
    return _valeurNO2;
}

double Measure::getValeurPM10() const
{
    return _valeurPM10;
}

time_t Measure::getDate() const
{
    return _date;
}

unsigned int Measure::getId() const
{
    return _id;
}

double Measure::getValeurO3() const
{
    return _valeurO3;
}
