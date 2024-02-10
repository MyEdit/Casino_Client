#ifndef P_SENDMODEL_H
#define P_SENDMODEL_H

#include <Network/networkclient.h>
#include <Network/PacketTypes.h>
#include <Utils/serializer.h>
#include <QStandardItemModel>

class P_SendModel
{
public:
    static QStandardItemModel* getModelFromServer();

private:
    friend class NetworkClient;
};

#endif // P_SENDMODEL_H
