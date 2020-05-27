#include "Actor.h"


Actor::Actor(const string & login,const string & password)
    :_login(login),_password(password)
{

}

bool Actor::connect(const string & login, const string & password)
{
    // A FAIRE
    return true;
}

bool Actor::disconnect()
{
    // A FAIRE
    return true;
}

string Actor::getLogin() const
{
    return this->_login;
}

string Actor::getPassword() const
{
    return this->_password;
}

void Actor::setLogin(const string & login)
{
    this->_login = login;
}

void Actor::setPassword(const string & password)
{
    this->_password = password;
}
