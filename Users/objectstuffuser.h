#ifndef OBJECTSTUFFUSER_H
#define OBJECTSTUFFUSER_H

#include "Users/objectuser.h"

class ObjectStuffUser : public ObjectUser
{
    static QList<ObjectStuffUser> stuffUsers;

    int ID{};
    QString name{};
    QString login{};
    Roles role{};

public:
    ObjectStuffUser() {}
    ObjectStuffUser(int ID, QString name, QString login, Roles role);

    //GETTERS
    int getID() override;
    QString getName() override;
    QString getLogin() override;
    Roles getRole() override;
    static QSharedPointer<ObjectStuffUser> deserializeUser(const QByteArray& data);
    QByteArray serializeUser() override;
};

#endif // OBJECTSTUFFUSER_H
