#include "Measure.h"

Measure::Measure(Catalog* catalog)
    :_catalog(catalog){

}

Measure::Measure(const unsigned int & id, const double &valeurO3, const double &valeurSO2, const double &valeurNO2, const double &valeurPM10, const time_t &date, Sensor* sensor)
    :_id(id),_valeurO3(valeurO3),_valeurS02(valeurSO2),_valeurNO2(valeurNO2),_valeurPM10(valeurPM10), _date(date), _sensor(sensor)
{

}

Sensor* Measure::getSensor() const
{
    return _sensor;
}

double Measure::getValueSO2() const
{
    return _valeurS02;
}

double Measure::getValueNO2() const
{
    return _valeurNO2;
}

double Measure::getValuePM10() const
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

double Measure::getValueO3() const
{
    return _valeurO3;
}

istream &operator>>(istream & in, Measure & measure) {
    string year, month, day, hour, minutes, seconds;
    getline(in, year, '-');
    getline(in, month, '-');
    getline(in, day, ' ');
    getline(in, hour, ':');
    getline(in, minutes, ':');
    getline(in, seconds, ';');

    time_t rawtime;
    time(&rawtime);

    tm *date{};
    date = localtime(&rawtime);
    date->tm_year = stoi(year);
    date->tm_mon = stoi(month);
    date->tm_mday = stoi(day);
    date->tm_hour = stoi(hour);
    date->tm_min = stoi(minutes);
    date->tm_sec = stoi(seconds);

    measure._date = mktime(date); // Converts tm struct to time_t

    string sensorId;
    getline(in, seconds, ';');
    sensorId = sensorId.substr(6, sensorId.size());

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
    measure._valeurS02 = stod(SO2);
    measure._valeurPM10 = stod(PM10);

    return in;
}
