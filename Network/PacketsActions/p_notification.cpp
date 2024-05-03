#include "p_notification.h"
#include "Utils/windowtracker.h"

QPair<TypeMessage, const QString> P_Notification::getTextNotification()
{
    TypeMessage typeMessage = NetworkClient::getMessageFromServer<TypeMessage>();
    return {typeMessage, NetworkClient::getMessageFromServer()};
}

void P_Notification::showNotification(QPair<TypeMessage, const QString&> notification)
{
    Notification::showNotification(notification.first, notification.second);
}
