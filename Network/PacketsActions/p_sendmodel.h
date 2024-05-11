#ifndef P_SENDMODEL_H
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
    static QSharedPointer<ModelData> getModelFromServer();
    static void setModel(QSharedPointer<ModelData>);
    static void initMapTableNames();
    static const QString& getTableName(ModelTypes modelType);

private:
    static QMap<ModelTypes, QString> tableNames;

    friend class NetworkClient;
};

#endif // P_SENDMODEL_H
