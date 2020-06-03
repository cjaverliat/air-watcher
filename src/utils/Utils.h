#ifndef AIRWATCHER_UTILS_H
#define AIRWATCHER_UTILS_H

#include <cmath>
#include "../application/data/Coordinates.h"

/**
 * @brief Convert degrees to radians
 *
 * @param degrees Degrees to convert into radians
 * @return Result of the radians conversion using the factor PI / 180
 */
double toRadians(double degrees);

/**
 * @brief Convert date time to elapsed seconds since epoch
 *
 * @param year
 * @param month
 * @param day
 * @param hours
 * @param minutes
 * @param seconds
 * @return Elapsed seconds since epoch
 */
time_t toEpoch(int year, int month, int day, int hours, int minutes, int seconds);

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
double haversineDistance(const Coordinates &c1, const Coordinates &c2);

#endif //AIRWATCHER_UTILS_H
