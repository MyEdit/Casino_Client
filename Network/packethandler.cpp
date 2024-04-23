#include "packethandler.h"

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
    emit signalReconnecting();

    while(!NetworkClient::connectToServer())
    {   
        sleep(5);
    }

    emit signalFinishReconnecting();

    P_Reconnection::sendUserData(P_Authorization::getActualUser());
    Message::logInfo("Reconnect to server successful");
}

void PacketHandler::packetHandler(PacketTypes packettype)
{   
    //TODO: Свернуть весь свитч в мапу указателей на функции
    switch(packettype)
    {
        case(PacketTypes::P_Authorization):
        {
            emit signalOpenForm(P_Authorization::getUser());
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
        case(PacketTypes::P_ConnectPlayerToTable):
        {
            emit signalOpenGame(P_ConnectPlayerToTable::getTable());
            break;
        }
        case(PacketTypes::P_ConnectOtherPlayerToTable):
        {
            emit signalUpdatePlayers(P_ConnectPlayerToTable::getTable());
            break;
        }
        case(PacketTypes::P_SendTables):
        {
            //А лучше передавать в сигнале лист новых столов, эстетичнее) emit signalSetTables(P_SendTables::getTablesFromServer());
            P_SendTables::getTablesFromServer();
            emit signalSetTables();
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
        case(PacketTypes::P_UpdateGameTimer):
        {
            emit signalUpdateTimer(P_UpdateGameTimer::getData());
            break;
        }
        case(PacketTypes::P_TakeCard):
        {
            emit signalTakeCard(P_TakeCard::takeCard());
            break;
        }
        case(PacketTypes::P_StartMove):
        {
            emit signalStartMove(P_StartMove::getMove());
            break;
        }
        case(PacketTypes::P_TakeCardAnotherPlayer):
        {
            emit signalTakeCardAnotherPlayer(P_TakeCard::takeCardAnotherPlayer());
            break;
        }
        default:
        {
            Message::logWarn("Server send unknown packettype");
            break;
        }
    }
}
