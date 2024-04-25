#include "objectuser.h"

ObjectUser::ObjectUser(const QString& fullName, const QString& passport, const QString& balance, const QString& login, const QString& password)
{
    this->fullName = fullName;
    this->passport = passport;
    this->balance = balance;
    this->login = login;
    this->password = password;
}

ObjectUser::ObjectUser(int id, const QString& fullName, const QString& passport, const QString& balance, const QString& login, const QString& password)
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

const QString& ObjectUser::getFullName()
{
    return fullName;
}

const QString& ObjectUser::getPassport()
{
    return passport;
}

const QString& ObjectUser::getBalance()
{
    return balance;
}

const QString& ObjectUser::getLogin()
{
    return login;
}

const QString& ObjectUser::getPassword()
{
    return password;
}

Roles ObjectUser::getRole()
{
    return role;
}

void ObjectUser::setFullName(const QString& fullName)
{
    this->fullName = fullName;
}

void ObjectUser::setPassport(const QString& passport)
{
    this->passport = passport;
}

void ObjectUser::setBalance(const QString& balance)
{
    this->balance = balance;
}

void ObjectUser::setLogin(const QString& login)
{
    this->login = login;
}

void ObjectUser::setPassword(const QString& password)
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
