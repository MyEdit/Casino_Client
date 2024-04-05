#include "objectstuffuser.h"

ObjectStuffUser::ObjectStuffUser(QString fullName, QString login, QString password, Roles role)
{
    this->fullName = fullName;
    this->login = login;
    this->password = password;
    this->role = role;
}

ObjectStuffUser::ObjectStuffUser(int id, QString fullName, QString login, QString password, Roles role)
{
    this->id = id;
    this->fullName = fullName;
    this->login = login;
    this->password = password;
    this->role = role;
}

int ObjectStuffUser::getID()
{
    return id;
}

QString ObjectStuffUser::getFullName()
{
    return fullName;
}

QString ObjectStuffUser::getLogin()
{
    return login;
}

QString ObjectStuffUser::getPassword()
{
    return password;
}

Roles ObjectStuffUser::getRole()
{
    return role;
}

void ObjectStuffUser::setFullName(QString fullName)
{
    this->fullName = fullName;
}

void ObjectStuffUser::setLogin(QString login)
{
    this->login = login;
}

void ObjectStuffUser::setPassword(QString password)
{
    this->password = password;
}

void ObjectStuffUser::setRole(Roles role)
{
    this->role = role;
}

bool ObjectStuffUser::inputDataIsValid()
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
