#include "p_sendtables.h"

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

        QSharedPointer<Table> newTable(new Table(receivedData));

        if(!Table::getTable(newTable->getSettings().ID))
        {
            Table::addTable(newTable);
        }
        else
        {
            QSharedPointer<Table> table = Table::getTable(newTable->getSettings().ID);
            table->setNewData(newTable->getSettings(), newTable->getGame()->getName(), newTable->getPlayers());
        }
    }
}

void P_SendTables::setTables()
{
    P_Authorization::playerW->setTabels();
}
