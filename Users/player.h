#ifndef OBJECTPLAYER_H
#define OBJECTPLAYER_H

#include "Users/user.h"

class Player : public User
{
    static QList<Player> players;

    int ID{};
    QString name{};
    QString login{};
    Roles role{};
    double balance{};

public:
    Player(int ID, QString name, double balance, QString login, Roles role);
    Player(const QByteArray& data);

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
