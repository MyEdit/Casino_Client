﻿#ifndef P_SENDMODEL_H
#define P_SENDMODEL_H

#include "Network/networkclient.h"
#include "Network/PacketTypes.h"
#include "Network/PacketsActions/p_authorization.h"
#include "Utils/serializer.h"
#include <QStandardItemModel>
#include <functional>

class P_SendModel
{
public:
    static ModelData getModelFromServer();
    static void setModel(ModelData);
    static QMap<ModelTypes, QString> tableNames;
    static void initMapTableNames();

private:
    static QMap<ModelTypes, std::function<void(ModelData)>> setModelFunctions;
    static void initMapFunctions();

    friend class NetworkClient;
};

#endif // P_SENDMODEL_H
