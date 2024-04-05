﻿#include "p_sendtables.h"

void P_SendTables::getTablesFromServer()
{
    int countTables;

    recv(NetworkClient::serverSocket, reinterpret_cast<char*>(&countTables), sizeof(int), 0);

    for(int i = 0; i < countTables; i++)
    {
        QByteArray receivedData;
        int dataSize;
        recv(NetworkClient::serverSocket, reinterpret_cast<char*>(&dataSize), sizeof(int), 0);
        receivedData.resize(dataSize);
        recv(NetworkClient::serverSocket, receivedData.data(), dataSize, 0);

        QSharedPointer<Table> table(Table::deserializeTable(receivedData));
        Table::addTables(table);
    }
}

void P_SendTables::setTables()
{
    P_Authorization::playerW->setTabels();
}