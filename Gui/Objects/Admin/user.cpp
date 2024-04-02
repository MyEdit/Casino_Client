#include "user.h"

User::User(QString fullName, QString passport, QString balance, QString login, QString password)
{
    this->fullName = fullName;
    this->passport = passport;
    this->balance = balance;
    this->login = login;
    this->password = password;
}

User::User(int id, QString fullName, QString passport, QString balance, QString login, QString password)
{
    this->id = id;
    this->fullName = fullName;
    this->passport = passport;
    this->balance = balance;
    this->login = login;
    this->password = password;
}

int User::getID()
{
    return id;
}

QString User::getFullName()
{
    return fullName;
}

QString User::getPassport()
{
    return passport;
}

QString User::getBalance()
{
    return balance;
}

QString User::getLogin()
{
    return login;
}

QString User::getPassword()
{
    return password;
}

Roles User::getRole()
{
    return role;
}

void User::setFullName(QString fullName)
{
    this->fullName = fullName;
}

void User::setPassport(QString passport)
{
    this->passport = passport;
}

void User::setBalance(QString balance)
{
    this->balance = balance;
}

void User::setLogin(QString login)
{
    this->login = login;
}

void User::setPassword(QString password)
{
    this->password = password;
}

bool User::inputDataIsValid()
{
    for (QString value : {fullName, passport, balance, login, password})
    {
        if (value.isEmpty())
            return false;
    }

    return true;
}
