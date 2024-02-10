﻿#include "packethandler.h"

void PacketHandler::run()
{
    clientHandler();
}

void PacketHandler::clientHandler()
{
    PacketTypes packettype;
    while(true)
    {
        if (recv(NetworkClient::serverSocket, (char*)&packettype, sizeof(PacketTypes), 0) <= 0)
        {
            //TODO: Вот тут, надо реализовать блокировку всех потоков и попытку реконнекта к серверу т.к в эту часть кода можно попасть только тогда, когда связь с сервером потеряна
            Message::logError("Сonnection to server was lost or an error occurred");
        }
        packetHandler(packettype);
    }
}

void PacketHandler::packetHandler(PacketTypes packettype)
{
    //TODO: Свернуть весь свитч в мапу указателей на функции
    switch(packettype)
    {
        case(PacketTypes::P_Authorization):
        {
            emit signalOpenForm();
            break;
        }
        case(PacketTypes::P_SendModel):
        {
            emit signalSetModelAllUsers(P_SendModel::getModelFromServer());
            break;
        }
        case(PacketTypes::P_Notification):
        {
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
        default:
        {
            Message::logWarn("Server send unknown packettype");
            break;
        }
    }
}