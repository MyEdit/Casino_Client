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
    ObjectStuffUser(const QString& fullName, const QString& login, const QString& password, Roles role);
    ObjectStuffUser(int id, const QString& fullName, const QString& login, const QString& password, Roles role);

    int getID();
    const QString& getFullName();
    const QString& getLogin();
    const QString& getPassword();
    Roles getRole();

    void setFullName(const QString& fullName);
    void setLogin(const QString& login);
    void setPassword(const QString& password);
    void setRole(const Roles role);

    bool inputDataIsValid() const;
};

#endif // OBJECTSTUFFUSER_H
