#ifndef OBJECTUSER_H
#define OBJECTUSER_H

#include <QString>
#include "Network/PacketTypes.h"

class ObjectUser
{
    int id {0};
    QString fullName;
    QString passport;
    QString balance;
    QString login;
    QString password;
    const Roles role = Roles::User;

public:
    ObjectUser() {};
    ObjectUser(QString fullName, QString passport, QString balance, QString login, QString password);
    ObjectUser(int id, QString fullName, QString passport, QString balance, QString login, QString password);

    int getID();
    QString getFullName();
    QString getPassport();
    QString getBalance();
    QString getLogin();
    QString getPassword();
    Roles getRole();

    void setFullName(QString fullName);
    void setPassport(QString passport);
    void setBalance(QString balance);
    void setLogin(QString login);
    void setPassword(QString password);

    bool inputDataIsValid();
};

#endif // OBJECTUSER_H
