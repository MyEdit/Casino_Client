#ifndef NOTIFICATIONUTIL_H
#define NOTIFICATIONUTIL_H

#include <QPair>
#include "Gui/Notification/notification.h"
#include "Utils/windowtracker.h"

class NotificationUtil
{
public:
    static void viewNotification(QPair<TypeMessage, QString> message)
    {
        Notification* notification = new Notification();
        notification->setAlertProperties(message.first, message.second, WindowTracker::activeWindow);
    }
};

#endif // NOTIFICATIONUTIL_H
