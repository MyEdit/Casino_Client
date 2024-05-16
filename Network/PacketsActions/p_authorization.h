#ifndef P_AUTHORIZATION_H
#define P_AUTHORIZATION_H

#include "Network/networkclient.h"
#include "Gui/window_admin.h"
#include "Gui/window_player.h"
#include "Users/player.h"
#include "Users/stuffuser.h"
#include <Network/PacketTypes.h>
#include "Constants.h"
#include <QMutex>

class Window_Admin;
class Window_Player;
class Window_Auth;
class Player;

class P_Authorization : public QObject
{
    Q_OBJECT

    static const PacketTypes packettype;
    static QSharedPointer<User> user;
    static QSharedPointer<Player> player;
    static QSharedPointer<StuffUser> stuffUser;
    static QMutex accessMutex;
    static Window_Auth* windowAuth;

public:
    static Window_Admin* adminW;
    static Window_Player* playerW;

    static void sendData(const QString& login, const QString& password);
    static void openMainWindow(QSharedPointer<User> user);
    static void setActualUser(QSharedPointer<User> newUser);
    static QSharedPointer<User> getActualUser();
    static QSharedPointer<User>getUser();
    static QSharedPointer<Player> getPlayer();
    static QSharedPointer<StuffUser> getStuffuser();
    static void showAuthWindow();
    static void setWindowAuth(Window_Auth *value);
};

#endif // P_AUTHORIZATION_H
