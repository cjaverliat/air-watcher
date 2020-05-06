#ifndef ACTOR_H
#define ACTOR_H

#include<iostream>
#include<string.h>

using namespace std;

class Actor
{
protected:
    string _login;
    string _password;
public:
    Actor(const string & login,const string & password);
    bool connect(const string & login,const string & password);
    bool disconnect();
    string getLogin() const;
    string getPassword() const;
    void setLogin(const string & login);
    void setPassword(const string & password);
};

#endif // ACTOR_H
