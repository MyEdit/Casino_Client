#ifndef P_NOTIFICATION_H
#define P_NOTIFICATION_H

#include "Network/networkclient.h"
#include "Gui/notification.h"
#include "Gui/reconnecting.h"

class P_Notification
{
public:
    static void viewNotification(QString message);
    static QString getTextNotification();
    static void viewReconnecting();
};

#endif // P_NOTIFICATION_H
