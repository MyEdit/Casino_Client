#ifndef PLAYER_H
#define PLAYER_H

#include "Users/user.h"

class Player : public User
{
    double balance{};

public:
    Player(int ID, QString name, double balance, QString login, Roles role);
    Player(const QByteArray& data);
    Player() {};

    //GETTERS
    int getID() override;
    QString getName() override;
    QString getLogin() override;
    Roles getRole() override;
    double getBalance();
    QByteArray getPhoto() override;

    //METHODS
    QByteArray serializeUser() override;
};

#endif // PLAYER_H
