#ifndef STUFFUSER_H
#define STUFFUSER_H

#include <QString>
#include "Network/PacketTypes.h"

class StuffUser
{
    int id;
    QString fullName;
    QString login;
    QString password;
    Roles role;

public:
    StuffUser(int id, QString fullName, QString login, QString password, Roles role);
    StuffUser(QString fullName, QString login, QString password, Roles role);

    int getID();
    QString getFullName();
    QString getLogin();
    QString getPassword();
    Roles getRole();

    bool inputDataIsValid();
};

#endif // STUFFUSER_H
