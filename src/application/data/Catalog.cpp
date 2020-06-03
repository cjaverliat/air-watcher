#include "Catalog.h"
#include <algorithm>

Catalog::Catalog()
{
}

const vector<Cleaner> &Catalog::getCleaners() const {
    return _cleaners;
}

const vector<Measure> &Catalog::getMeasures()  const{
    return _measures;
}

const vector<Sensor> &Catalog::getSensors()  const{
    return _sensors;
}

const vector<Provider> &Catalog::getProviders()  const{
    return _providers;
}

const vector<PrivateIndividual> &Catalog::getPrivateIndividuals()  const{
    return _privateIndividuals;
}

Sensor* Catalog::getSensorById(unsigned int sensorId) {
    for (unsigned i(0); i < _sensors.size(); ++i){
        if(_sensors[i].getId() == sensorId){
            return &(_sensors[i]);
        }
    }
    return nullptr;
}

Cleaner* Catalog::getCleanerById(unsigned int cleanerId) {
    for (unsigned i(0); i < _cleaners.size(); ++i){
        if(_cleaners[i].getId() == cleanerId){
            return &(_cleaners[i]);
        }
    }
    return nullptr;
}

std::vector<std::pair<double, const Sensor *>> Catalog::getSensorsAroundCleaner(const Cleaner &cleaner) {
    std::vector<std::pair<double, const Sensor *>> sensorsAround;
    for (Sensor & _sensor : _sensors){
        double d = haversineDistance(cleaner.getCoordinates(), _sensor.getCoordinates());
        sensorsAround.emplace_back(d, &_sensor);
    }

    //Trie les capteurs par distance au cleaner
    sort(sensorsAround.begin(), sensorsAround.end(), Catalog::comparePair);
    return sensorsAround;
}

bool Catalog::comparePair(const std::pair<double, const Sensor *> &p1, const std::pair<double, const Sensor *> &p2)
{
    return (p1.first < p2.first);
}
