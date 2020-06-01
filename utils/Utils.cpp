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

double haversineDistance(const Coordinates &c1, const Coordinates &c2)
{
    int r = 6371; //Earth radius in kilometers
    double alpha = (c2.getLatitude() - c1.getLatitude()) / 2;
    double beta = (c2.getLongitude() - c1.getLongitude()) / 2;
    double distance = 2 * r * asin(sqrt(pow(sin(alpha), 2) + cos(c1.getLatitude()) * cos(c2.getLatitude()) * pow(sin(beta), 2)));

    //assert(distance >= 0);
    return distance;
}