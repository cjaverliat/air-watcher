#include "Services.h"

#include <cmath>
#include <cassert>

#include <algorithm>

const unsigned int idxLevelsO3[9] = {29, 54, 79, 104, 129, 149, 179, 209, 239};
const unsigned int idxLevelsSO2[9] = {39, 79, 119, 159, 199, 249, 299, 399, 499};
const unsigned int idxLevelsNO2[9] = {29, 54, 84, 109, 134, 164, 199, 274, 399};
const unsigned int idxLevelsPM10[9] = {6, 13, 20, 27, 34, 41, 49, 64, 79};

using namespace std;

Services::Services(Catalog &catalog) : m_catalog(catalog) {}

int Services::computeATMOIndex(const Measure &measure) const {
    int atmoIdx = 1;
    const unsigned int *idxLevels;

    double maxConcentration = 0;

    if (measure.getValueO3() > maxConcentration) {
        maxConcentration = measure.getValueO3();
        idxLevels = idxLevelsO3;
    }
    if (measure.getValueSO2() > maxConcentration) {
        maxConcentration = measure.getValueSO2();
        idxLevels = idxLevelsSO2;
    }
    if (measure.getValueNO2() > maxConcentration) {
        maxConcentration = measure.getValueNO2();
        idxLevels = idxLevelsNO2;
    }
    if (measure.getValuePM10() > maxConcentration) {
        maxConcentration = measure.getValuePM10();
        idxLevels = idxLevelsPM10;
    }

    while (maxConcentration >= idxLevels[atmoIdx - 1]) {
        atmoIdx += 1;
        if (atmoIdx == 10) {
            break;
        }
    }

    assert(atmoIdx >= 1 && atmoIdx <= 10);
    return atmoIdx;
}

const Measure *Services::getLastSensorMeasure(const Sensor &sensor, time_t t) const {
    assert(is_sorted(m_catalog.getMeasures().begin(), m_catalog.getMeasures().end(), Measure::dateComparator));

    //Parcourt en sens inverse
    for (auto it = m_catalog.getMeasures().end() - 1; it >= m_catalog.getMeasures().begin(); --it) {
        if (it->getSensor()->getId() == sensor.getId() && it->getDate() <= t) {
            return &(*it);
        }
    }

    return nullptr;
}

std::vector<const Measure *> Services::getSensorMeasuresInPeriod(const Sensor &sensor, time_t startTime, time_t endTime) const {
    assert(difftime(endTime, startTime) >= 0);
    assert(is_sorted(m_catalog.getMeasures().begin(), m_catalog.getMeasures().end(), Measure::dateComparator));

    std::vector<const Measure *> measures;

    for (const Measure &m : m_catalog.getMeasures()) {
        if (sensor.getId() == m.getSensor()->getId() && difftime(m.getDate(), startTime) >= 0 && difftime(endTime, m.getDate()) >= 0) {
            measures.push_back(&m);
        }
    }

    return measures;
}

std::vector<const Measure *> Services::getSensorMeasures(const Sensor &sensor) const {
    assert(is_sorted(m_catalog.getMeasures().begin(), m_catalog.getMeasures().end(), Measure::dateComparator));

    std::vector<const Measure *> measures;

    for (const Measure &m : m_catalog.getMeasures()) {
        if (sensor.getId() == m.getSensor()->getId()) {
            measures.push_back(&m);
        }
    }

    return measures;
}

double Services::meanAirQuality(const Coordinates &zoneCenter, double zoneRadius, time_t t) const {
    unsigned int idxSum = 0;
    double n = 0;

    for (const Sensor &sensor : m_catalog.getSensors()) {
        double d = haversineDistance(zoneCenter, sensor.getCoordinates());

        if (d <= zoneRadius) {
            const Measure *lastMeasure = getLastSensorMeasure(sensor, t);

            if (lastMeasure != nullptr) {
                idxSum += computeATMOIndex(*lastMeasure);
                ++n;
            }
        }
    }

    if (n > 0) {
        cout << "Moyenne sur les dernières données de " << n << " capteur(s)." << endl;
        return idxSum / n;
    } else {
        cout << "Aucune donnée disponible avec les paramètres choisis." << endl;
        return -1;
    }
}

double Services::meanAirQuality(const Coordinates &zoneCenter, double zoneRadius, time_t startTime, time_t endTime) const {
    assert(difftime(endTime, startTime) >= 0);

    unsigned int idxSum = 0;
    double n = 0;
    double nSensors = 0;

    for (const Sensor &sensor : m_catalog.getSensors()) {
        double d = haversineDistance(zoneCenter, sensor.getCoordinates());
        bool used = false;

        if (d <= zoneRadius) {
            std::vector<const Measure *> measures = getSensorMeasuresInPeriod(sensor, startTime, endTime);

            for (const Measure *m : measures) {
                idxSum += computeATMOIndex(*m);
                ++n;
                used = true;
            }
        }

        if (used) {
            ++nSensors;
        }
    }

    if (n > 0) {
        cout << n << " donnée(s) utilisée(s), utilisant " << nSensors << " capteur(s)." << endl;
        return idxSum / n;
    } else {
        cout << "Aucune donnée disponible à ce moment dans cette zone." << endl;
        return -1;
    }
}

std::vector<const Sensor *> Services::getSimilarSensors(const Sensor &refSensor, double epsilonATMOIndex, double epsilonTime) const {
    std::vector<const Sensor *> similarSensors;

    std::vector<const Measure *> refSensorMeasures = getSensorMeasures(refSensor);

    for (const Sensor &sensor : m_catalog.getSensors()) {
        if (sensor.getId() == refSensor.getId())
            continue;

        bool similarMeasures = true;
        std::vector<const Measure *> currentSensorMeasures = getSensorMeasures(sensor);
        assert(std::is_sorted(currentSensorMeasures.begin(), currentSensorMeasures.end()));

        if (currentSensorMeasures.size() == 0) {
            continue;
        }

        for (unsigned i = 0; i < std::min(refSensorMeasures.size(), currentSensorMeasures.size()); ++i) {
            const Measure &refMeasure = *refSensorMeasures.at(i);
            const Measure &currentSensorMeasure = *currentSensorMeasures.at(i);
            bool atmoIndexSimilar = abs(computeATMOIndex(refMeasure) - computeATMOIndex(currentSensorMeasure)) <= epsilonATMOIndex;
            bool timeSimilar = abs(difftime(refMeasure.getDate(), currentSensorMeasure.getDate())) <= epsilonTime;

            if (!atmoIndexSimilar || !timeSimilar) {
                similarMeasures = false;
                break;
            }
        }

        if (similarMeasures) {
            similarSensors.push_back(&sensor);
        }
    }

    return similarSensors;
}

std::pair<std::string, double> Services::getZoneCaracteristicAttribute(const Coordinates &zoneCenter, double zoneRadius, time_t t) const {
    double sumO3 = 0;
    double sumSO2 = 0;
    double sumNO2 = 0;
    double sumPM10 = 0;

    unsigned int n = 0;

    for (const Sensor &sensor : m_catalog.getSensors()) {
        double d = haversineDistance(sensor.getCoordinates(), zoneCenter);

        if (d <= zoneRadius) {
            const Measure &lastSensorMeasure = *getLastSensorMeasure(sensor, t);
            sumO3 += lastSensorMeasure.getValueO3();
            sumSO2 += lastSensorMeasure.getValueSO2();
            sumNO2 += lastSensorMeasure.getValueNO2();
            sumPM10 += lastSensorMeasure.getValuePM10();
            ++n;
        }
    }

    if (n > 0) {
        double meanO3 = sumO3 / n;
        double meanSO2 = sumSO2 / n;
        double meanNO2 = sumNO2 / n;
        double meanPM10 = sumPM10 / n;

        double maxConcentration = std::max(meanO3, std::max(meanSO2, std::max(meanNO2, meanPM10)));

        if (maxConcentration == meanO3) {
            return std::make_pair("O3", meanO3);
        } else if (maxConcentration == meanSO2) {
            return std::make_pair("SO2", meanSO2);
        } else if (maxConcentration == meanNO2) {
            return std::make_pair("NO2", meanNO2);
        } else {
            return std::make_pair("PM10", meanPM10);
        }
    } else {
        return std::make_pair("", -1);
    }
}

std::pair<double, double> Services::computeCleanerImpact(const Cleaner &cleaner) const {
    int improvementsSum = 0;
    int nbImprovements = 0;
    double impactRadius = 0;

    std::vector<std::pair<double, const Sensor *>> sensorsAround = m_catalog.getSensorsAroundCleaner(cleaner);

    //Sorted by increasing distance
    assert(std::is_sorted(sensorsAround.begin(), sensorsAround.end(),
                          [](const std::pair<double, const Sensor *> &p1, const std::pair<double, const Sensor *> &p2) {
                              return p1.first < p2.first;
                          }));

    for (auto &mapEntry : sensorsAround) {
        double distance = mapEntry.first; //Distance between the sensor and the air cleaner
        const Sensor &sensor = *mapEntry.second;

        int idxATMOBefore = computeATMOIndex(*getLastSensorMeasure(sensor, cleaner.getCleanerStart() - 1));
        int idxATMOAfter = computeATMOIndex(*getLastSensorMeasure(sensor, cleaner.getCleanerStop()));

        if (idxATMOAfter < idxATMOBefore) {
            improvementsSum += idxATMOBefore - idxATMOAfter;
            ++nbImprovements;
            impactRadius = distance;
        } else {
            break;
        }
    }

    if (nbImprovements > 0) {
        double meanImprovement = double(improvementsSum) / nbImprovements;
        return std::make_pair(impactRadius, meanImprovement);
    } else {
        return std::make_pair(0, 0);
    }
}