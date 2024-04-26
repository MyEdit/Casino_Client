#include "objectstuffuser.h"

ObjectStuffUser::ObjectStuffUser(const QString& fullName, const QString& login, const QString& password, Roles role)
{
    this->fullName = fullName;
    this->login = login;
    this->password = password;
    this->role = role;
}

ObjectStuffUser::ObjectStuffUser(int id, const QString& fullName, const QString& login, const QString& password, Roles role)
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

const QString& ObjectStuffUser::getFullName()
{
    return fullName;
}

const QString& ObjectStuffUser::getLogin()
{
    return login;
}

const QString& ObjectStuffUser::getPassword()
{
    return password;
}

Roles ObjectStuffUser::getRole()
{
    return role;
}

void ObjectStuffUser::setFullName(const QString& fullName)
{
    this->fullName = fullName;
}

void ObjectStuffUser::setLogin(const QString& login)
{
    this->login = login;
}

void ObjectStuffUser::setPassword(const QString& password)
{
    this->password = password;
}

void ObjectStuffUser::setRole(const Roles role)
{
    this->role = role;
}

bool ObjectStuffUser::inputDataIsValid() const
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
