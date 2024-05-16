#ifndef P_RECONNECTING_H
#define P_RECONNECTING_H

#include "Network/networkclient.h"
#include "Gui/Notification/reconnecting.h"
#include "Utils/windowtracker.h"
#include "Users/user.h"

class P_Reconnection
{
    static QSharedPointer<Reconnecting> reconnecting;

public:
    static void viewReconnecting();
    static void stopReconnecting();
};

#endif // P_RECONNECTING_H
