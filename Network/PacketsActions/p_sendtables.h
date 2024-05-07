#ifndef P_SENDTABLES_H
#define P_SENDTABLES_H

#include <QByteArray>
#include <QSharedPointer>
#include "Games/Tabel/table.h"
#include "Network/networkclient.h"

class Table;

class P_SendTables
{
public:
    static void getTablesFromServer();
    static void setTables();
    static void deleteTable(const QList<QSharedPointer<Table>>& newTables);
};

#endif // P_SENDTABLES_H
