#include "Catalog.h"

Catalog::Catalog()
{
}

const vector<Cleaner> &Catalog::getCleaners() const {
    return _cleaners;
}

const vector<Measure> &Catalog::getMeasures() const {
    return _measures;
}

const vector<Sensor> &Catalog::getSensors() const {
    return _sensors;
}

const vector<Provider> &Catalog::getProviders() const {
    return _providers;
}

const vector<PrivateIndividual> &Catalog::getPrivateIndividuals() const {
    return _privateIndividuals;
}
