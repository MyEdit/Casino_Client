#include "p_notification.h"
#include "Utils/windowtracker.h"

QString P_Notification::getTextNotification()
{
    return NetworkClient::getMessageFromServer();
}

void P_Notification::viewNotification(QString message)
{
    Notification* notification = new Notification();
    notification->setAlertProperties(TypeMessage::Information, message, WindowTracker::activeWindow);
}
