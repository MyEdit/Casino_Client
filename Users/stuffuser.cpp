#include "stuffuser.h"

StuffUser::StuffUser(int ID, QString name, QString login, Roles role)
{
    this->ID = ID;
    this->name = name;
    this->login = login;
    this->role = role;
}

StuffUser::StuffUser(const QByteArray& data)
{
    QDataStream stream(data);
    int ID;
    QString name, login;
    int roleInt;
    QByteArray photoData;
    stream >> ID >> name >> login >> roleInt >> photoData;

    Roles role = static_cast<Roles>(roleInt);

    this->ID = ID;
    this->name = name;
    this->login = login;
    this->role = role;
    this->photo = QSharedPointer<QByteArray>::create(photoData);
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

QSharedPointer<QByteArray> StuffUser::getPhoto()
{
    return this->photo;
}

const QByteArray StuffUser::serializeUser()
{
    QByteArray byteArray;
    QDataStream stream(&byteArray, QIODevice::WriteOnly);
    stream << ID;
    stream << name;
    stream << login;
    stream << static_cast<int>(role);
    stream << photo;
    return byteArray;
}

