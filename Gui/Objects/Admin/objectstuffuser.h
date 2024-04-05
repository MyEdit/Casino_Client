#ifndef OBJECTSTUFFUSER_H
#define OBJECTSTUFFUSER_H

#include <QString>
#include "Network/PacketTypes.h"

class ObjectStuffUser
{
    int id {0};
    QString fullName;
    QString login;
    QString password;
    Roles role;

public:
    ObjectStuffUser() {};
    ObjectStuffUser(QString fullName, QString login, QString password, Roles role);
    ObjectStuffUser(int id, QString fullName, QString login, QString password, Roles role);

    int getID();
    QString getFullName();
    QString getLogin();
    QString getPassword();
    Roles getRole();

    void setFullName(QString fullName);
    void setLogin(QString login);
    void setPassword(QString password);
    void setRole(Roles role);

    bool inputDataIsValid();
};

#endif // OBJECTSTUFFUSER_H
