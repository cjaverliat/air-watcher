#include "Catalog.h"

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