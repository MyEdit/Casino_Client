#include "Users/user.h"

int User::getID() const
{
    return ID;
}

const QString &User::getName()
{
    return name;
}

const QString &User::getLogin()
{
    return login;
}

Roles User::getRole() const
{
    return role;
}

const QSharedPointer<QByteArray> User::getPhoto()
{
    return photo;
}
