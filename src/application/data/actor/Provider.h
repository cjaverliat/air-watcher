#ifndef PROVIDER_H
#define PROVIDER_H

#include "Actor.h"
#include "application/data/Cleaner.h"
#include "application/data/Catalog.h"

class Catalog;

class Provider : public Actor
{
protected:
    Cleaner* _cleaner;
    Catalog* _catalog;
public:
    Provider(Catalog* catalog);
    Provider(const string & login,const string & password, Cleaner* & cleaner);
    Cleaner* getCleaner() const;
    void setCleaner(Cleaner* cleaner);
    friend istream & operator >> (istream & in, Provider & provider);
};

#endif // PROVIDER_H
