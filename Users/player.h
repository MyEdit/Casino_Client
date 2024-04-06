#ifndef PLAYER_H
#define PLAYER_H

#include "Users/user.h"

class Player : public User
{
    int ID{};
    QString name{};
    QString login{};
    Roles role{};
    double balance{};

public:
    Player(int ID, QString name, double balance, QString login, Roles role);
    Player(const QByteArray& data);
    Player();

    //GETTERS
    int getID() override;
    QString getName() override;
    QString getLogin() override;
    Roles getRole() override;
    double getBalance();

    //METHODS
    QByteArray serializeUser() override;
};

#endif // PLAYER_H
