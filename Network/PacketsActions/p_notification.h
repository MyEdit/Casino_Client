#ifndef P_NOTIFICATION_H
#define P_NOTIFICATION_H

#include "Network/networkclient.h"
#include "Gui/Notification/notification.h"

class P_Notification
{
public:
    static QPair<TypeMessage, const QString> getTextNotification();
    static void showNotification(QPair<TypeMessage, const QString&> notification);
};

#endif // P_NOTIFICATION_H
