#ifndef OBJECTUSER_H
#define OBJECTUSER_H

#include <QString>
#include <Network/PacketTypes.h>

class ObjectUser
{
public:
    virtual ~ObjectUser() {}

    //GETTERS
    virtual int getID() {}
    virtual QString getName() {}
    virtual QString getLogin() {}
    virtual Roles getRole() {}
    virtual QByteArray serializeUser() {}
};

#endif // OBJECTUSER_H
