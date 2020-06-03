#ifndef CLEANER_H
#define CLEANER_H

#include<iostream>
#include<string.h>
#include<time.h>
#include"Coordinates.h"

using namespace std;

class Cleaner
{
protected:
    unsigned int _id;
    string _description;
    time_t _cleanerStart;
    time_t _cleanerStop;
    Coordinates _coordinates;
public:
    Cleaner();
    Cleaner(const unsigned int & id,string  description, const time_t & cleanerStart,const time_t & cleanerStop, const Coordinates & coordinates);
    string getDescription() const;
    void setDescription(const string &description);
    time_t getCleanerStart() const;
    time_t getCleanerStop() const;
    void setCleanerStop(const time_t &cleanerStop);
    Coordinates getCoordinates() const;
    void setCoordinates(const Coordinates &coordinates);
    unsigned int getId() const;
    friend istream & operator >> (istream & in, Cleaner & cleaner);
};

#endif // CLEANER_H
