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

    //GETTERS
    int getID() override;
    QString getName() override;
    QString getLogin() override;
    Roles getRole() override;
    static QSharedPointer<StuffUser> deserializeUser(const QByteArray& data);
    QByteArray serializeUser() override;
};

#endif // OBJECTSTUFFUSER_H
