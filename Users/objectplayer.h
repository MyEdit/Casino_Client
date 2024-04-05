#ifndef OBJECTPLAYER_H
#define OBJECTPLAYER_H

#include "Users/user.h"

class ObjectPlayer : public User
{
    static QList<ObjectPlayer> players;

    int ID{};
    QString name{};
    QString login{};
    Roles role{};
    double balance{};

public:
    ObjectPlayer(int ID, QString name, double balance, QString login, Roles role);

    //GETTERS
    int getID() override;
    QString getName() override;
    QString getLogin() override;
    Roles getRole() override;
    double getBalance();
    static QSharedPointer<ObjectPlayer> deserializeUser(const QByteArray& data);
    QByteArray serializeUser() override;
};

#endif // OBJECTPLAYER_H
