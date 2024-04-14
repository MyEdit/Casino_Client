#include "p_connectplayertotable.h"

QSharedPointer<Table> P_ConnectPlayerToTable::getTable()
{
    int idTable;
    recv(NetworkClient::serverSocket, reinterpret_cast<char*>(&idTable), sizeof(int), 0);

    QSharedPointer<Table> table = Table::getTable(idTable);
    return table;
}

void P_ConnectPlayerToTable::openGameGUI(QSharedPointer<Table> table)
{
    table->openGameGUI();
}
