﻿#ifndef STUFFUSER_H
#define STUFFUSER_H

#include <QString>
#include "Network/PacketTypes.h"

class StuffUser
{
    int id {0};
    QString fullName;
    QString login;
    QString password;
    Roles role;

public:
    StuffUser() {};
    StuffUser(QString fullName, QString login, QString password, Roles role);
    StuffUser(int id, QString fullName, QString login, QString password, Roles role);

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

#endif // STUFFUSER_H
