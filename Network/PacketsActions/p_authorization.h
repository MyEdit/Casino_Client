#ifndef P_AUTHORIZATION_H
#define P_AUTHORIZATION_H

#include "Network/networkclient.h"
#include "GUI/window_admin.h"
#include <Network/PacketTypes.h>

class Window_Admin;

class P_Authorization : public QObject
{
    Q_OBJECT

    static const PacketTypes packettype;
    static QString nickname;

public:
    static Window_Admin* adminW;

    static void sendData(QString login, QString password);
    static void openMainWindow(Roles role);
    static void setActualNickname(QString nickname);
    static QString& getActualNickname();
    static Roles getRole();
};

#endif // P_AUTHORIZATION_H
