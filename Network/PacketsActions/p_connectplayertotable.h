#ifndef P_CONNECTPLAYERTOTABLE_H
#define P_CONNECTPLAYERTOTABLE_H

#include "Games/Tabel/table.h"
#include <QSharedPointer>

class Table;

class P_ConnectPlayerToTable
{
public:
    static QSharedPointer<Table> getTable();
    static void openGameGUI(QSharedPointer<Table> table);
    static void updatePlayers(QSharedPointer<Table> table);
};

#endif // P_CONNECTPLAYERTOTABLE_H
