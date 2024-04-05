#include "p_reconnection.h"

const PacketTypes P_Reconnection::packettype = PacketTypes::P_Reconnection;
Reconnecting* P_Reconnection::reconnecting;

void P_Reconnection::viewReconnecting()
{
    reconnecting = new Reconnecting();
    reconnecting->setAlertProperties(WindowTracker::activeWindow);
}

void P_Reconnection::stopReconnecting()
{
    reconnecting->close();
    delete reconnecting;
}

void P_Reconnection::sendUserData(QSharedPointer<User> actualUser)
{
    QByteArray byteUser = actualUser->serializeUser();
    int sizeByteUser = byteUser.size();
    Roles role = actualUser->getRole();

    NetworkClient::sendToServer(&packettype, sizeof(PacketTypes));
    NetworkClient::sendToServer(&role, sizeof(Roles));
    NetworkClient::sendToServer(&sizeByteUser, sizeof(int));
    NetworkClient::sendToServer(byteUser.constData(), sizeByteUser);
}
