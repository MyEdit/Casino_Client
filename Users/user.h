#ifndef OBJECTUSER_H
#define OBJECTUSER_H

#include <QString>
#include <Network/PacketTypes.h>

class User
{
public:
    virtual ~User() {}

    //GETTERS
    virtual int getID() = 0;
    virtual QString getName() = 0;
    virtual QString getLogin() = 0;
    virtual Roles getRole() = 0;
    virtual QByteArray serializeUser() = 0;
};

#endif // USER_H
