#include "packethandler.h"

PacketHandler::PacketHandler()
{
    initPacketHandlerFunction();
}

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

    //P_Reconnection::sendUserData(P_Authorization::getActualUser());
    Message::logInfo("Reconnect to server successful");
}

void PacketHandler::initPacketHandlerFunction()
{
    packetHandlerFunction =
    {
        {PacketTypes::P_Authorization,              [&]() {emit signalOpenForm(P_Authorization::getUser());}},
        {PacketTypes::P_SendModel,                  [&]() {emit signalSetModel(P_SendModel::getModelFromServer());}},
        {PacketTypes::P_Notification,               [&]() {emit signalViewNotification(P_Notification::getTextNotification());}},
        {PacketTypes::P_ConnectPlayerToTable,       [&]() {emit signalOpenGame(P_ConnectPlayerToTable::getTable());}},
        {PacketTypes::P_ConnectOtherPlayerToTable,  [&]() {emit  signalUpdatePlayers(P_ConnectPlayerToTable::getTable());}},
        {PacketTypes::P_SendTables,                 [&]() {P_SendTables::getTablesFromServer(); emit signalSetTables();}},
        {PacketTypes::P_QueryWithoutResponce,       [&]() {}},
        {PacketTypes::P_Query,                      [&]() {emit signalSetQueryModel(P_Query::getResultFromServer());}},
        {PacketTypes::P_UpdateGameProcessing,       [&]() {emit signalUpdateGameProcessing(P_UpdateGameProcessing::getData());}},
        {PacketTypes::P_GamePacket,                 [&]() {P_GamePacket::onGamePacketReceived();}},
        {PacketTypes::P_Search,                     [&]() {emit signalResultSearch(P_Search::getResultSearchFromServer());}},
        {PacketTypes::P_UpdateBalance,              [&]() {emit signalUpdateBalance(P_UpdateBalance::getNewBalance());}},
        {PacketTypes::P_Update,                     [&]() {emit signalUpdateTable(P_Update::getModelFromServer());}},
        {PacketTypes::P_PlayerLeaveTable,           [&]() {}}
    };
}

void PacketHandler::packetHandler(const PacketTypes packettype)
{   
    if(packetHandlerFunction.contains(packettype))
        packetHandlerFunction[packettype]();
    else
        Message::logWarn("Server send unknown packettype");
}
