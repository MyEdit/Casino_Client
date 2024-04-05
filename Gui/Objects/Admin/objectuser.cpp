#include "objectuser.h"

ObjectUser::ObjectUser(QString fullName, QString passport, QString balance, QString login, QString password)
{
    this->fullName = fullName;
    this->passport = passport;
    this->balance = balance;
    this->login = login;
    this->password = password;
}

ObjectUser::ObjectUser(int id, QString fullName, QString passport, QString balance, QString login, QString password)
{
    this->id = id;
    this->fullName = fullName;
    this->passport = passport;
    this->balance = balance;
    this->login = login;
    this->password = password;
}

int ObjectUser::getID()
{
    return id;
}

QString ObjectUser::getFullName()
{
    return fullName;
}

QString ObjectUser::getPassport()
{
    return passport;
}

QString ObjectUser::getBalance()
{
    return balance;
}

QString ObjectUser::getLogin()
{
    return login;
}

QString ObjectUser::getPassword()
{
    return password;
}

Roles ObjectUser::getRole()
{
    return role;
}

void ObjectUser::setFullName(QString fullName)
{
    this->fullName = fullName;
}

void ObjectUser::setPassport(QString passport)
{
    this->passport = passport;
}

void ObjectUser::setBalance(QString balance)
{
    this->balance = balance;
}

void ObjectUser::setLogin(QString login)
{
    this->login = login;
}

void ObjectUser::setPassword(QString password)
{
    this->password = password;
}

bool ObjectUser::inputDataIsValid()
{
    for (QString value : {fullName, passport, balance, login, password})
    {
        if (value.isEmpty())
            return false;
    }

    return true;
}
