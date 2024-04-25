#include "p_reconnection.h"

const PacketTypes P_Reconnection::packettype = PacketTypes::P_Reconnection;
QSharedPointer<Reconnecting> P_Reconnection::reconnecting;

void P_Reconnection::viewReconnecting()
{
    reconnecting = QSharedPointer<Reconnecting>(new Reconnecting());
    reconnecting->setAlertProperties(WindowTracker::activeWindow);
}

void P_Reconnection::stopReconnecting()
{
    reconnecting->close();
    reconnecting.clear();
}

void P_Reconnection::sendUserData(QSharedPointer<User> user)
{
    QByteArray byteUser = user->serializeUser();
    int sizeByteUser = byteUser.size();
    Roles role = user->getRole();

    NetworkClient::sendToServer(&packettype, sizeof(PacketTypes));
    NetworkClient::sendToServer(&role, sizeof(Roles));
    NetworkClient::sendToServer(&sizeByteUser, sizeof(int));
    NetworkClient::sendToServer(byteUser.constData(), sizeByteUser);
}
