#ifndef P_AUTHORIZATION_H
#define P_AUTHORIZATION_H

#include "Network/networkclient.h"
#include "Gui/window_admin.h"
#include "Gui/window_player.h"
#include <Network/PacketTypes.h>

class Window_Admin;

class P_Authorization : public QObject
{
    Q_OBJECT

    static const PacketTypes packettype;
    static QString nickname;

public:
    static Window_Admin* adminW;
    static Window_Player* playerW;

    static void sendData(QString login, QString password);
    static void openMainWindow(UserData user);
    static void setActualNickname(QString nickname);
    static QString& getActualNickname();
    static UserData getUser();
};

#endif // P_AUTHORIZATION_H
