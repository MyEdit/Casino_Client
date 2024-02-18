#ifndef P_NOTIFICATION_H
#define P_NOTIFICATION_H

#include "Network/networkclient.h"
#include "GUI/notification.h"

class P_Notification
{
public:
    static void viewNotification(QString message);
    static QString getTextNotification();
};

#endif // P_NOTIFICATION_H
