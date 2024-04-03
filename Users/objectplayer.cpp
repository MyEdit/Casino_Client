#include "objectplayer.h"

ObjectPlayer::ObjectPlayer(int ID, QString name, double balance, QString login, Roles role)
{
    this->ID = ID;
    this->name = name;
    this->balance = balance;
    this->login = login;
    this->role = role;
}

int ObjectPlayer::getID()
{
    return this->ID;
}

QString ObjectPlayer::getName()
{
    return this->name;
}
QString ObjectPlayer::getLogin()
{
    return this->login;
}

Roles ObjectPlayer::getRole()
{
    return this->role;
}

double ObjectPlayer::getBalance()
{
    return this->balance;
}

QSharedPointer<ObjectPlayer> ObjectPlayer::deserializeUser(const QByteArray& data)
{
    QDataStream stream(data);
    int id;
    QString name, login;
    double balance;
    int roleInt;
    stream >> id >> name >> balance >> login >> roleInt;
    Roles role = static_cast<Roles>(roleInt);

    return QSharedPointer<ObjectPlayer>::create(id, name, balance, login, role);
}

QByteArray ObjectPlayer::serializeUser()
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
