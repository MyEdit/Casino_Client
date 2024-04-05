#include "stuffuser.h"

StuffUser::StuffUser(int ID, QString name, QString login, Roles role)
{
    this->ID = ID;
    this->name = name;
    this->login = login;
    this->role = role;
}

int StuffUser::getID()
{
    return this->ID;
}

QString StuffUser::getName()
{
    return this->name;
}
QString StuffUser::getLogin()
{
    return this->login;
}

Roles StuffUser::getRole()
{
    return this->role;
}

QSharedPointer<StuffUser> StuffUser::deserializeUser(const QByteArray& data)
{
    QDataStream stream(data);
    int id;
    QString name, login;
    int roleInt;
    stream >> id >> name >> login >> roleInt;
    Roles role = static_cast<Roles>(roleInt);

    return QSharedPointer<StuffUser>::create(id, name, login, role);
}

QByteArray StuffUser::serializeUser()
{
    QByteArray byteArray;
    QDataStream stream(&byteArray, QIODevice::WriteOnly);
    stream << ID;
    stream << name;
    stream << login;
    stream << static_cast<int>(role);
    return byteArray;
}

