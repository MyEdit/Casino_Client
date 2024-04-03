#ifndef OBJECTPLAYER_H
#define OBJECTPLAYER_H

#include "Users/objectuser.h"

class ObjectPlayer : public ObjectUser
{
    static QList<ObjectPlayer> players;

    int ID{};
    QString name{};
    QString login{};
    Roles role{};
    double balance{};

public:
    ObjectPlayer() {}
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
