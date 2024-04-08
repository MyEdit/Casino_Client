#ifndef USER_H
#define USER_H

#include <QString>
#include <Network/PacketTypes.h>

class User
{
public:
    int ID{};
    QString name{};
    QString login{};
    Roles role{};
    QByteArray photo{};

    virtual ~User() {}

    //GETTERS
    virtual int getID() = 0;
    virtual QString getName() = 0;
    virtual QString getLogin() = 0;
    virtual Roles getRole() = 0;
    virtual QByteArray getPhoto() = 0;
    virtual QByteArray serializeUser() = 0;
};

#endif // USER_H
