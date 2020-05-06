#ifndef CATALOG_H
#define CATALOG_H

#include"measure.h"
#include"sensor.h"
#include"cleaner.h"
#include"../acteurs/provider.h"
#include"../acteurs/privateindividual.h"
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
};

#endif // CATALOG_H
