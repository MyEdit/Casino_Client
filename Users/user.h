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
    QSharedPointer<QByteArray> photo{};

    virtual ~User() {}

    //GETTERS
    int getID() const;
    const QString& getName();
    const QString& getLogin();
    Roles getRole() const;
    const QSharedPointer<QByteArray> getPhoto();
    virtual QSharedPointer<QByteArray> serializeUser() = 0;
};

#endif // USER_H
