#include "p_notification.h"
#include "Utils/windowtracker.h"

QPair<TypeMessage, QString> P_Notification::getTextNotification()
{
    TypeMessage typeMessage;
    recv(NetworkClient::serverSocket, reinterpret_cast<char*>(&typeMessage), sizeof(typeMessage), 0);
    return QPair<TypeMessage, QString>(typeMessage, NetworkClient::getMessageFromServer());
}

void P_Notification::viewNotification(QPair<TypeMessage, QString> message)
{
    Notification* notification = new Notification();
    notification->setAlertProperties(message.first, message.second, WindowTracker::activeWindow);
}
