#include "p_notification.h"

QString P_Notification::getTextNotification()
{
    return NetworkClient::getMessageFromServer();
}

void P_Notification::viewNotification(QString message)
{
    Notification* notification = new Notification();
    notification->setAlertProperties(TypeMessage::Information, message, qApp->activeWindow());
}
