#ifndef P_QUERY_H
#define P_QUERY_H

#include "Network/networkclient.h"
#include "Network/PacketTypes.h"
#include "Utils/serializer.h"
#include <QStandardItemModel>
#include "Network/PacketsActions/p_authorization.h"

class P_Query
{
public:
    static QString getResultFromServer();

private:
    friend class NetworkClient;
};
#endif // P_QUERY_H
