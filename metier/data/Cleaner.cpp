#include "cleaner.h"

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
