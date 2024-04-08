#ifndef STUFFUSER_H
#define STUFFUSER_H

#include "Users/user.h"

class StuffUser : public User
{
public:
    StuffUser(int ID, QString name, QString login, Roles role);
    StuffUser(const QByteArray& data);
    StuffUser();

    //GETTERS
    int getID() override;
    QString getName() override;
    QString getLogin() override;
    Roles getRole() override;
    QByteArray getPhoto() override;

    //METHODS
    QByteArray serializeUser() override;
};

#endif // STUFFUSER_H
