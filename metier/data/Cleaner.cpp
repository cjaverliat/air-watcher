#include "Cleaner.h"
#include "../../utils/Utils.h"

Cleaner::Cleaner() {

}

Cleaner::Cleaner(const unsigned int & id, const string &description, const time_t &cleanerStart, const time_t &cleanerStop, const Coordinates & coordinates)
    :_id(id),_description(description),_cleanerStart(cleanerStart),_cleanerStop(cleanerStop),_coordinates(coordinates)
{

}

unsigned int Cleaner::getId() const
{
    return _id;
}

string Cleaner::getDescription() const
{
    return _description;
}

void Cleaner::setDescription(const string &description)
{
    _description = description;
}

time_t Cleaner::getCleanerStart() const
{
    return _cleanerStart;
}

time_t Cleaner::getCleanerStop() const
{
    return _cleanerStop;
}

void Cleaner::setCleanerStop(const time_t &cleanerStop)
{
    _cleanerStop = cleanerStop;
}

Coordinates Cleaner::getCoordinates() const
{
    return _coordinates;
}

void Cleaner::setCoordinates(const Coordinates &coordinates)
{
    _coordinates = coordinates;
}

istream & operator >> (istream & in, Cleaner & cleaner)
{
    string id;
    getline(in, id, ';');
    id = id.substr(7, id.size() - 7);
    cleaner._id = stoi(id);

    string longitude, latitude;
    getline(in, latitude, ';');
    getline(in, longitude, ';');
    cleaner._coordinates = Coordinates(toRadians(stod(latitude)), toRadians(stod(longitude)));

    string description;
    getline(in, description, ';');
    cleaner._description = description;

    string year, month, day, hour, minutes, seconds;
    getline(in, year, '-');
    getline(in, month, '-');
    getline(in, day, ' ');
    getline(in, hour, ':');
    getline(in, minutes, ':');
    getline(in, seconds, ';');

    time_t rawtime;
    time(&rawtime);

    tm *cleanerStart{};
    cleanerStart = localtime(&rawtime);
    cleanerStart->tm_year = stoi(year);
    cleanerStart->tm_mon = stoi(month);
    cleanerStart->tm_mday = stoi(day);
    cleanerStart->tm_hour = stoi(hour);
    cleanerStart->tm_min = stoi(minutes);
    cleanerStart->tm_sec = stoi(seconds);

    cleaner._cleanerStart = mktime(cleanerStart); // Converts tm struct to time_t

    getline(in, year, '-');
    getline(in, month, '-');
    getline(in, day, ' ');
    getline(in, hour, ':');
    getline(in, minutes, ':');
    getline(in, seconds, ';');

    tm *cleanerStop{};
    cleanerStop = localtime(&rawtime);
    cleanerStop->tm_year = stoi(year);
    cleanerStop->tm_mon = stoi(month);
    cleanerStop->tm_mday = stoi(day);
    cleanerStop->tm_hour = stoi(hour);
    cleanerStop->tm_min = stoi(minutes);
    cleanerStop->tm_sec = stoi(seconds);

    cleaner._cleanerStop = mktime(cleanerStop); // Converts tm struct to time_t

    return in;
}
