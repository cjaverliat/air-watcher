#ifndef PROVIDER_H
#define PROVIDER_H

#include"actor.h"
#include"../data/cleaner.h"

class Provider : public Actor
{
protected:
    Cleaner _cleaner;
public:
    Provider(const string & login,const string & password, const Cleaner & cleaner);
    Cleaner getCleaner() const;
    void setCleaner(const Cleaner &cleaner);
};

#endif // PROVIDER_H
