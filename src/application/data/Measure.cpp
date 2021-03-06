#include "Measure.h"

Measure::Measure(Catalog* catalog)
    :_catalog(catalog){

}

Measure::Measure(const double &valeurO3, const double &valeurSO2, const double &valeurNO2, const double &valeurPM10, const time_t &date, Sensor* sensor)
    :_valeurO3(valeurO3),_valeurSO2(valeurSO2),_valeurNO2(valeurNO2),_valeurPM10(valeurPM10), _date(date), _sensor(sensor)
{
}

Sensor* Measure::getSensor() const
{
    return _sensor;
}

double Measure::getValueSO2() const
{
    return _valeurSO2;
}

double Measure::getValueNO2() const
{
    return _valeurNO2;
}

double Measure::getValuePM10() const
{
    return _valeurPM10;
}

double Measure::getValueO3() const
{
    return _valeurO3;
}

time_t Measure::getDate() const
{
    return _date;
}

istream &operator>>(istream & in, Measure & measure) {
    string year, month, day, hour, minutes, seconds;
    getline(in, year, '-');
    getline(in, month, '-');
    getline(in, day, ' ');
    getline(in, hour, ':');
    getline(in, minutes, ':');
    getline(in, seconds, ';');

    measure._date = toEpoch(stoi(year), stoi(month), stoi(day), stoi(hour), stoi(minutes), stoi(seconds));

    string sensorId;
    getline(in, sensorId, ';');
    sensorId = sensorId.substr(6, sensorId.size() - 6);

    measure._sensor = measure._catalog->getSensorById(stoi(sensorId));

    string tmp, O3, NO2, SO2, PM10;
    getline(in, tmp, ';');
    getline(in, O3, ';');
    getline(in, tmp, ';');
    getline(in, tmp, ';');
    getline(in, tmp, ';');
    getline(in, NO2, ';');
    getline(in, tmp, ';');
    getline(in, tmp, ';');
    getline(in, tmp, ';');
    getline(in, SO2, ';');
    getline(in, tmp, ';');
    getline(in, tmp, ';');
    getline(in, tmp, ';');
    getline(in, PM10, ';');
    getline(in, tmp, '\n');

    measure._valeurO3 = stod(O3);
    measure._valeurNO2 = stod(NO2);
    measure._valeurSO2 = stod(SO2);
    measure._valeurPM10 = stod(PM10);

    return in;
}

bool Measure::dateComparator(const Measure &m1, const Measure &m2) {
    return m1.getDate() < m2.getDate();
}