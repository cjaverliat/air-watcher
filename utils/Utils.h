#ifndef AIRWATCHER_UTILS_H
#define AIRWATCHER_UTILS_H

#include <cmath>

double toRadians(double degrees);

time_t toEpoch(int year, int month, int day, int hours, int minutes, int seconds);

#endif //AIRWATCHER_UTILS_H
