#ifndef CATALOG_H
#define CATALOG_H

#include"Measure.h"
#include"Sensor.h"
#include"Cleaner.h"
#include"../acteurs/Provider.h"
#include"../acteurs/PrivateIndividual.h"
#include<vector>
#include<map>

class Provider;
class PrivateIndividual;

using namespace std;

class Measure;

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

    Sensor* getSensorById(unsigned int sensorId);

    Cleaner* getCleanerById(unsigned int cleanerId);

    std::map<double, const Sensor *> getSensorsAroundCleaner(Cleaner cleaner);

    friend class CSVParser;
};

#endif // CATALOG_H
