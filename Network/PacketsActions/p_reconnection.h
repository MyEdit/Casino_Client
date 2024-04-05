#ifndef P_RECONNECTING_H
#define P_RECONNECTING_H

#include "Network/networkclient.h"
#include "GUI/Notification/reconnecting.h"
#include "Utils/windowtracker.h"
#include "Users/user.h"

class P_Reconnection
{
    static Reconnecting* reconnecting;
    static const PacketTypes packettype;

public:
    static void viewReconnecting();
    static void stopReconnecting();
    static void sendUserData(QSharedPointer<User> actualUser);
};

#endif // P_RECONNECTING_H
