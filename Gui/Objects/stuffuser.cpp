#include "stuffuser.h"

StuffUser::StuffUser()
{
}

StuffUser::StuffUser(QString fullName, QString login, QString password, Roles role)
{
    this->fullName = fullName;
    this->login = login;
    this->password = password;
    this->role = role;
}

StuffUser::StuffUser(int id, QString fullName, QString login, QString password, Roles role)
{
    this->id = id;
    this->fullName = fullName;
    this->login = login;
    this->password = password;
    this->role = role;
}

int StuffUser::getID()
{
    return id;
}

QString StuffUser::getFullName()
{
    return fullName;
}

QString StuffUser::getLogin()
{
    return login;
}

QString StuffUser::getPassword()
{
    return password;
}

Roles StuffUser::getRole()
{
    return role;
}

void StuffUser::setFullName(QString fullName)
{
    this->fullName = fullName;
}

void StuffUser::setLogin(QString login)
{
    this->login = login;
}

void StuffUser::setPassword(QString password)
{
    this->password = password;
}

void StuffUser::setRole(Roles role)
{
    this->role = role;
}

bool StuffUser::inputDataIsValid()
{
    if (role == Roles::None)
        return false;

    for (QString value : {fullName, login, password})
    {
        if (value.isEmpty())
            return false;
    }

    return true;
}
