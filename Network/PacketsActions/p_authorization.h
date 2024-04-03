#ifndef P_AUTHORIZATION_H
#define P_AUTHORIZATION_H

#include "Network/networkclient.h"
#include "Gui/window_admin.h"
#include "Gui/window_player.h"
#include "Users/objectplayer.h"
#include "Users/objectstuffuser.h"
#include <Network/PacketTypes.h>

class Window_Admin;
class Window_Player;

class P_Authorization : public QObject
{
    Q_OBJECT

    static const PacketTypes packettype;
    static QSharedPointer<ObjectUser> actualUser;

public:
    static Window_Admin* adminW;
    static Window_Player* playerW;

    static void sendData(QString login, QString password);
    static void openMainWindow(QSharedPointer<ObjectUser> user);
    static void setActualUser(QSharedPointer<ObjectUser> user);
    static QSharedPointer<ObjectUser> getActualUser();
    static QSharedPointer<ObjectUser>getUser();
};

#endif // P_AUTHORIZATION_H
