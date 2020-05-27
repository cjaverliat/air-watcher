#ifndef CATALOG_H
#define CATALOG_H

#include"Measure.h"
#include"Sensor.h"
#include"Cleaner.h"
#include"../acteurs/Provider.h"
#include"../acteurs/Privateindividual.h"
#include<vector>

using namespace std;

class Catalog
{
protected:
    vector<Cleaner> _cleaners;
    vector<Measure> _measures;
    vector<Sensor> _sensors;
    vector<Provider> _providers;
    vector<PrivateIndividual> _privateIndividuals;
public:
    Catalog();

    const vector<Cleaner> &getCleaners() const;

    const vector<Measure> &getMeasures() const;

    const vector<Sensor> &getSensors() const;

    const vector<Provider> &getProviders() const;

    const vector<PrivateIndividual> &getPrivateIndividuals() const;
};

#endif // CATALOG_H
