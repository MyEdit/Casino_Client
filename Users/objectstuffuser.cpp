#include "objectstuffuser.h"

ObjectStuffUser::ObjectStuffUser(int ID, QString name, QString login, Roles role)
{
    this->ID = ID;
    this->name = name;
    this->login = login;
    this->role = role;
}

int ObjectStuffUser::getID()
{
    return this->ID;
}

QString ObjectStuffUser::getName()
{
    return this->name;
}
QString ObjectStuffUser::getLogin()
{
    return this->login;
}

Roles ObjectStuffUser::getRole()
{
    return this->role;
}

QSharedPointer<ObjectStuffUser> ObjectStuffUser::deserializeUser(const QByteArray& data)
{
    QDataStream stream(data);
    int id;
    QString name, login;
    int roleInt;
    stream >> id >> name >> login >> roleInt;
    Roles role = static_cast<Roles>(roleInt);

    return QSharedPointer<ObjectStuffUser>::create(id, name, login, role);
}

QByteArray ObjectStuffUser::serializeUser()
{
    QByteArray byteArray;
    QDataStream stream(&byteArray, QIODevice::WriteOnly);
    stream << ID;
    stream << name;
    stream << login;
    stream << static_cast<int>(role);
    return byteArray;
}

