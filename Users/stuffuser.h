#ifndef STUFFUSER_H
#define STUFFUSER_H

#include "Users/user.h"

class StuffUser : public User
{
    int ID{};
    QString name{};
    QString login{};
    Roles role{};

public:
    StuffUser(int ID, QString name, QString login, Roles role);
    StuffUser(const QByteArray& data);
    StuffUser();

    //GETTERS
    int getID() override;
    QString getName() override;
    QString getLogin() override;
    Roles getRole() override;

    //METHODS
    QByteArray serializeUser() override;
};

#endif // STUFFUSER_H
