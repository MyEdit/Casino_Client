#include "clienthandler.h"

void ClientHandler::run()
{
    PacketTypes packettype;
    while(true)
    {
        if (recv(NetworkClient::serverSocket, (char*)&packettype, sizeof(PacketTypes), 0) <= 0)
        {
            Message::logError("Impossible, Fix me!!!");
        }
        else
            emit signalPacketHandler(packettype);
    }
}
