#pragma once

#include <string>
#include <vector>
#include <ctime>
#include <utility>
#include <map>

#include "../data/Measure.h"
#include "../data/Coordinates.h"
#include "../data/Sensor.h"
#include "../data/Catalog.h"
#include "../data/Cleaner.h"

class Services
{

private:
    Catalog &m_catalog;

public:
    Services(Catalog &catalog);

    /**
     * @brief Compute the ATMO index
     * 
     * Compute the ATMO index according to the table available on Wikipedia:
     * https://fr.wikipedia.org/wiki/Indice_de_qualit%C3%A9_de_l'air#Indice_Atmo 
     * 
     * @param measure The measure containing the concentration of O3, SO2, NO2 and PM10 to compute the index.
     * @return The ATMO index, between 1 and 10.
     */
    int computeATMOIndex(const Measure &measure) const;

    /**
     * @brief Compute the Haversine distance between two coordinates
     * 
     * Compute the Harversine distance between two coordinates according to the Wikipedia formula:
     * https://fr.wikipedia.org/wiki/Formule_de_haversine
     * 
     * @param c1 The first coordinates (longitude, latitude).
     * @param c2 The second coordinates (longitude, latitude).
     * @return The distance between the two points, in kilometers.
     */
    double haversineDistance(const Coordinates &c1, const Coordinates &c2) const;

    /**
     * @brief Get the last sensor measure
     * 
     * @param sensor The sensor to return the last measure from.
     * @param t The time under which we will take the last sensor measure.
     * @return The last measure of the sensor, or nullptr if none.
     */
    const Measure *getLastSensorMeasure(const Sensor &sensor, time_t t) const;

    /**
     * @brief Get the sensor Measures on a given period
     * 
     * @param sensor The sensor to return the measures from.
     * @param startTime The start time of the time period.
     * @param endTime The end time of the time period.
     * @return The list of all the measures included in the given time period.
     */
    std::vector<const Measure *> getSensorMeasuresInPeriod(const Sensor &sensor, time_t startTime, time_t endTime) const;

    /**
     * @brief Get all the sensor measures
     * 
     * @param sensor The sensor to return the measures from.
     * @return The list of all the measures for the given sensor.
     */
    std::vector<const Measure *> getSensorMeasures(const Sensor &sensor) const;

    /**
     * @brief Compute the mean air quality in the given zone at a given time
     * 
     * Compute the mean air quality from all sensors inside the given zone.
     * 
     * @param zoneCenter The coordinates of the center of the zone.
     * @param zoneRadius The radius of the zone.
     * @param t The time under which we will take air quality from each sensor.
     * @return The mean air quality (this is an ATMO index), between 1 and 10. 
     */
    double meanAirQuality(const Coordinates &zoneCenter, double zoneRadius, time_t t) const;
    /**
     * @brief Compute the mean air quality in the given zone over a timespan
     * 
     * Compute the mean air quality from all sensors inside the given zone over the given timespan.
     * 
     * @param zoneCenter The coordinates of the center of the zone.
     * @param zoneRadius The radius of the zone.
     * @param startTime The start time of the time period.
     * @param endTime The end time of the time period.
     * @return The mean air quality (this is an ATMO index), between 1 and 10. 
     */
    double meanAirQuality(const Coordinates &zoneCenter, double zoneRadius, time_t startTime, time_t endTime) const;

    /**
     * @brief Get all the similar sensors of a reference one
     * 
     * @param refSensor The reference sensor.
     * @param epsilonATMOIndex Epsilon used to check if the difference of ATMO index of a reference measure and another sensor's measure is small enough.
     * @param epsilonTime Epsilon used to check if the difference of time of a reference measure and another sensor's measure is small enough.
     * @return The list of all sensors similar to the reference sensor.
     */
    std::vector<const Sensor *> getSimilarSensors(const Sensor &refSensor, double epsilonATMOIndex, double epsilonTime) const;

    /**
     * @brief Get the zone caracteristic attribute
     * 
     * @param zoneCenter The coordinates of the center of the zone.
     * @param zoneRadius The radius of the zone.
     * @param t The time under which we will take the zone caracteristic attribute.
     * @return A pair consisting of the attributeID and its average concentration in the zone.
     */
    std::pair<std::string, double> getZoneCaracteristicAttribute(const Coordinates &zoneCenter, double zoneRadius, time_t t) const;

    /**
     * @brief Compute the impact of an air cleaner
     * 
     * @param cleaner The air cleaner to compute the impact of.
     * @return A pair consisting of the impact radius and the average ATMO index improvement.
     */
    std::pair<double, double> computeCleanerImpact(const Cleaner &cleaner) const;
};