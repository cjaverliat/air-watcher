#ifndef CATALOG_H
#define CATALOG_H

#include <gtest/gtest_prod.h>
#include "Measure.h"
#include "Sensor.h"
#include "Cleaner.h"
#include "../data/actor/Provider.h"
#include "../data/actor/PrivateIndividual.h"
#include "../../utils/Utils.h"
#include <vector>
#include <map>

class Provider;

class PrivateIndividual;

using namespace std;

class Measure;

class Catalog {
protected:
    FRIEND_TEST(ParsingTest, parseProvider);
    vector<Cleaner> _cleaners;
    vector<Measure> _measures;
    FRIEND_TEST(ParsingTest, parseMeasure);
    FRIEND_TEST(ParsingTest, parseUser);
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

    Sensor *getSensorById(unsigned int sensorId);

    Cleaner *getCleanerById(unsigned int cleanerId);

    std::vector<std::pair<double, const Sensor *>> getSensorsAroundCleaner(const Cleaner &cleaner);

    friend class CSVParser;

    static bool comparePair(const std::pair<double, const Sensor *> &p1, const std::pair<double, const Sensor *> &p2);
};

#endif // CATALOG_H
