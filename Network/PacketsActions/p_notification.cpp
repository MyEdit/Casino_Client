#include "p_notification.h"
#include "Utils/windowtracker.h"

QPair<TypeMessage, const QString> P_Notification::getTextNotification()
{
    TypeMessage typeMessage;
    recv(NetworkClient::serverSocket, reinterpret_cast<char*>(&typeMessage), sizeof(typeMessage), 0);
    return {typeMessage, NetworkClient::getMessageFromServer()};
}
