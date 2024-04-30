#include "p_sendtables.h"

void P_SendTables::getTablesFromServer()
{
    int countTables = NetworkClient::getMessageFromServer<int>();

    for(int i = 0; i < countTables; i++)
    {
        int dataSize = NetworkClient::getMessageFromServer<int>();
        QByteArray receivedData = NetworkClient::getMessageFromServer<QByteArray>(dataSize);

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
