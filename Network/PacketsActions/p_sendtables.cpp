﻿#include "p_sendtables.h"

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
            table->setNewData(newTable->getSettings(), newTable->getGame()->getName(), newTable->getPlayers(), newTable->getIsGameRunning());
        }
    }
}

void P_SendTables::setTables()
{
    if (P_Authorization::playerW)
        P_Authorization::playerW->setTabels();
}

void P_SendTables::deleteTable(const QList<QSharedPointer<Table>>& newTables)
{
    QList<QSharedPointer<Table>>& oldTables = Table::getTabels();

    for (auto it = oldTables.begin(); it != oldTables.end(); it++)
    {
        bool found = false;
        int tableID = it->get()->getSettings().ID;
        for (const auto& currentTable : newTables)
        {
            if (currentTable->getSettings().ID == tableID)
            {
                found = true;
                break;
            }
        }

        if (!found)
            oldTables.erase(it);
    }
}
