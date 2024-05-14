#include "p_connectplayertotable.h"

QSharedPointer<Table> P_ConnectPlayerToTable::getTable()
{
    int tableID = NetworkClient::getMessageFromServer<int>();
    QSharedPointer<Table> table = Table::getTable(tableID);
    return table;
}

void P_ConnectPlayerToTable::openGameGUI(QSharedPointer<Table> table)
{
    table->openGameGUI();
}

void P_ConnectPlayerToTable::updatePlayers(QSharedPointer<Table> table)
{
    if(table)
        table->updatePlayers();
}
