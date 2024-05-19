#ifndef STUFFUSER_H
#define STUFFUSER_H

#include "Users/user.h"

class StuffUser : public User
{
public:
    StuffUser(int ID, const QString& name, const QString& login, Roles role);
    StuffUser(const QByteArray& data);
    StuffUser();

    //METHODS
    QSharedPointer<QByteArray> serializeUser() override;
};

#endif // STUFFUSER_H
