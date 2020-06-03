#include "Provider.h"

Provider::Provider(Catalog* catalog)
    : _catalog(catalog){

}

Provider::Provider(const string & email,const string & password, Cleaner* & cleaner)
    :Actor(email,password),_cleaner(cleaner)
{

}

Cleaner* Provider::getCleaner() const
{
    return _cleaner;
}

void Provider::setCleaner(Cleaner* cleaner)
{
    _cleaner = cleaner;
}

istream & operator>>(istream & in, Provider & provider) {
    string providerId, cleanerId, tmp;
    getline(in, providerId, ';');
    getline(in, cleanerId, ';');
    getline(in, tmp, '\n');

    cleanerId = cleanerId.substr(7, cleanerId.size() - 7);

    provider._login = providerId;

    provider._cleaner = provider._catalog->getCleanerById(stoi(cleanerId));

    return in;
}


