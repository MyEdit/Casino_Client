#include "player.h"

Player::Player(int ID, QString name, double balance, QString login, Roles role)
{
    this->ID = ID;
    this->name = name;
    this->balance = balance;
    this->login = login;
    this->role = role;
}

Player::Player(const QByteArray& data)
{
    QDataStream stream(data);
    int ID;
    QString name, login;
    double balance;
    int roleInt;
    stream >> ID >> name >> balance >> login >> roleInt;
    Roles role = static_cast<Roles>(roleInt);

    this->ID = ID;
    this->name = name;
    this->balance = balance;
    this->login = login;
    this->role = role;
}

int Player::getID()
{
    return this->ID;
}

QString Player::getName()
{
    return this->name;
}
QString Player::getLogin()
{
    return this->login;
}

Roles Player::getRole()
{
    return this->role;
}

double Player::getBalance()
{
    return this->balance;
}

QByteArray Player::serializeUser()
{
    QByteArray byteArray;
    QDataStream stream(&byteArray, QIODevice::WriteOnly);
    stream << ID;
    stream << name;
    stream << balance;
    stream << login;
    stream << static_cast<int>(role);
    return byteArray;
}
