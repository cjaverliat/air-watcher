#include "Provider.h"

Provider::Provider(const string & email,const string & password, const Cleaner & cleaner)
    :Actor(email,password),_cleaner(cleaner)
{

}

Cleaner Provider::getCleaner() const
{
    return _cleaner;
}

void Provider::setCleaner(const Cleaner &cleaner)
{
    _cleaner = cleaner;
}
