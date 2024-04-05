#ifndef P_AUTHORIZATION_H
#define P_AUTHORIZATION_H

#include "Network/networkclient.h"
#include "Gui/window_admin.h"
#include "Gui/window_player.h"
#include "Users/objectplayer.h"
#include "Users/stuffuser.h"
#include <Network/PacketTypes.h>

class Window_Admin;
class Window_Player;

class P_Authorization : public QObject
{
    Q_OBJECT

    static const PacketTypes packettype;
    static QSharedPointer<User> actualUser;

public:
    static Window_Admin* adminW;
    static Window_Player* playerW;

    static void sendData(QString login, QString password);
    static void openMainWindow(QSharedPointer<User> user);
    static void setActualUser(QSharedPointer<User> user);
    static QSharedPointer<User> getActualUser();
    static QSharedPointer<User>getUser();
};

#endif // P_AUTHORIZATION_H
