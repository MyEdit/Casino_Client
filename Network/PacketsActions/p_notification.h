#ifndef P_NOTIFICATION_H
#define P_NOTIFICATION_H

#include "Network/networkclient.h"
#include "GUI/Notification/notification.h"

class P_Notification
{
public:
    static void viewNotification(QPair<TypeMessage, QString> message);
    static QPair<TypeMessage, QString> getTextNotification();
};

#endif // P_NOTIFICATION_H
