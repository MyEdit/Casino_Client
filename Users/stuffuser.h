#ifndef STUFFUSER_H
#define STUFFUSER_H

#include "Users/user.h"

class StuffUser : public User
{
public:
    StuffUser(int ID, QString name, QString login, Roles role);
    StuffUser(const QByteArray& data);
    StuffUser();

    //GETTERS
    int getID() override;
    const QString& getName() override;
    const QString& getLogin() override;
    Roles getRole() override;
    QSharedPointer<QByteArray> getPhoto() override;

    //METHODS
    QSharedPointer<QByteArray> serializeUser() override;
};

#endif // STUFFUSER_H
