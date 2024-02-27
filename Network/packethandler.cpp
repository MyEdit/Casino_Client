#include "packethandler.h"
#include "Gui/reconnecting.h"

void PacketHandler::run()
{
    clientHandler();
}

void PacketHandler::clientHandler()
{
    PacketTypes packettype;
    while(true)
    {
        if (recv(NetworkClient::serverSocket, reinterpret_cast<char*>(&packettype), sizeof(PacketTypes), 0) <= 0)
        {
            NetworkClient::onServerDisconnected();
            tryReconnectToServer();
            continue;
        }
        packetHandler(packettype);
    }
}

void PacketHandler::tryReconnectToServer()
{
    //TODO: Тут нужно вызвать окно с таймером реконнекта
    while(!NetworkClient::connectToServer())
    {

        sleep(5);
    }
    //TODO: Сделать новый тип пакета P_Reconnection и отсылать отсюда серверу свой ник, дабы он по возможности добавил его в мапу Conections (Ведь сервер мог перезагрузиться, следовательно и мапа Conections тогда будет пуста)
    Message::logInfo("Reconnect to server successful");
}

void PacketHandler::packetHandler(PacketTypes packettype)
{
    //TODO: Свернуть весь свитч в мапу указателей на функции
    switch(packettype)
    {
        case(PacketTypes::P_Authorization):
        {
            emit signalOpenForm(P_Authorization::getRole());
            break;
        }
        case(PacketTypes::P_SendModel):
        {
            emit signalSetModel(P_SendModel::getModelFromServer());
            break;
        }
        case(PacketTypes::P_Notification):
        {
            emit signalViewNotification(P_Notification::getTextNotification());
            break;
        }
        case(PacketTypes::P_DeleteTable):
        {
            break;
        }
        case(PacketTypes::P_AddTable):
        {
            break;
        }
        case(PacketTypes::P_ConnectPlayerToTable):
        {
            break;
        }
        case(PacketTypes::P_SendTables):
        {
            break;
        }
        case(PacketTypes::P_QueryWithoutResponce):
        {
            emit signalSetQueryModel(P_Query::getResultFromServer());
            break;
        }
        case(PacketTypes::P_Query):
        {
            break;
        }
        default:
        {
            Message::logWarn("Server send unknown packettype");
            break;
        }
    }
}
