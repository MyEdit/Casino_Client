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
    ObjectUser(const QString& fullName, const QString& passport, const QString& balance, const QString& login, const QString& password);
    ObjectUser(int id, const QString& fullName, const QString& passport, const QString& balance, const QString& login, const QString& password);

    int getID();
    const QString& getFullName();
    const QString& getPassport();
    const QString& getBalance();
    const QString& getLogin();
    const QString& getPassword();
    Roles getRole();

    void setFullName(const QString& fullName);
    void setPassport(const QString& passport);
    void setBalance(const QString& balance);
    void setLogin(const QString& login);
    void setPassword(const QString& password);

    bool inputDataIsValid();
};

#endif // OBJECTUSER_H
