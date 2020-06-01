#include <ctime>
#include "Utils.h"

double toRadians(double degrees) {
    return double(M_PI) / 180.0 * degrees;
}

time_t toEpoch(int year, int month, int day, int hours, int minutes, int seconds) {

    time_t epoch;

    tm *timeInfo;
    time(&epoch);

    timeInfo = localtime(&epoch);
    timeInfo->tm_year = year - 1900;
    timeInfo->tm_mon = month - 1;
    timeInfo->tm_mday = day;
    timeInfo->tm_hour = hours;
    timeInfo->tm_min = minutes;
    timeInfo->tm_sec = seconds;

    return mktime (timeInfo);
}