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

void P_Reconnection::sendUserData(QString nickname)
{
    NetworkClient::sendToServer(&packettype, sizeof(PacketTypes));
    NetworkClient::sendToServer(nickname);
}
