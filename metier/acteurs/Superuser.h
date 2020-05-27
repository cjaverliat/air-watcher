#ifndef SUPERUSER_H
#define SUPERUSER_H

#include"Actor.h"

class SuperUser : public Actor
{
public:
    SuperUser(const string & login,const string & password);
};

#endif // SUPERUSER_H
