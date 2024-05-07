#include "p_sendtables.h"

void P_SendTables::getTablesFromServer()
{
    int countTables = NetworkClient::getMessageFromServer<int>();

    QList<QSharedPointer<Table>> newTables;

    for(int i = 0; i < countTables; i++)
    {
        int dataSize = NetworkClient::getMessageFromServer<int>();
        QByteArray receivedData = NetworkClient::getMessageFromServer<QByteArray>(dataSize);

        QSharedPointer<Table> newTable(new Table(receivedData));
        newTables.append(newTable);
    }

    deleteTable(newTables);

    for(QSharedPointer<Table> newTable : newTables)
    {
        if(!Table::getTable(newTable->getSettings().ID))
            Table::addTable(newTable);
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

void P_SendTables::deleteTable(const QList<QSharedPointer<Table>>& newTables)
{
    QList<QSharedPointer<Table>>& oldTables = Table::getTabels();
    QSharedPointer<Game> playerGame = P_Authorization::getPlayer()->getGame();

    for (auto it = oldTables.begin(); it != oldTables.end();)
    {
         bool found = false;
         for (const auto& currentTable : newTables)
         {
             if (currentTable->getSettings().ID == it->get()->getSettings().ID)
             {
                 found = true;
                 break;
             }
         }

         if (!found)
         {
             if (playerGame->getTableID() == it->get()->getSettings().ID)
                playerGame->getGUI()->close();

             it = oldTables.erase(it);
         }
         else
             ++it;
     }
}
