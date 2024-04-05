#ifndef OBJECTSTUFFUSER_H
#define OBJECTSTUFFUSER_H

#include "Users/user.h"

class StuffUser : public User
{
    static QList<StuffUser> stuffUsers;

    int ID{};
    QString name{};
    QString login{};
    Roles role{};

public:
    StuffUser(int ID, QString name, QString login, Roles role);
    StuffUser(const QByteArray& data);

    //GETTERS
    int getID() override;
    QString getName() override;
    QString getLogin() override;
    Roles getRole() override;

    //METHODS
    QByteArray serializeUser() override;
};

#endif // STUFFUSER_H
