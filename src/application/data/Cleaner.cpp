#include "Cleaner.h"

#include "../../utils/Utils.h"

Cleaner::Cleaner() {

}

Cleaner::Cleaner(const unsigned int & id, string description, const time_t &cleanerStart, const time_t &cleanerStop, const Coordinates & coordinates)
    :_id(id),_description(std::move(description)),_cleanerStart(cleanerStart),_cleanerStop(cleanerStop),_coordinates(coordinates)
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
    cleaner._coordinates = Coordinates(stod(latitude), stod(longitude));

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

    cleaner._cleanerStart = toEpoch(stoi(year), stoi(month), stoi(day), stoi(hour), stoi(minutes), stoi(seconds));

    getline(in, year, '-');
    getline(in, month, '-');
    getline(in, day, ' ');
    getline(in, hour, ':');
    getline(in, minutes, ':');
    getline(in, seconds, ';');

    cleaner._cleanerStop = toEpoch(stoi(year), stoi(month), stoi(day), stoi(hour), stoi(minutes), stoi(seconds));

    return in;
}
