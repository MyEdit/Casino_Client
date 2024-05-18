#include "p_sendmodel.h"

QMap<ModelTypes, QString> P_SendModel::tableNames;

QSharedPointer<ModelData> P_SendModel::getModelFromServer()
{
    ModelTypes modeltype = NetworkClient::getMessageFromServer<ModelTypes>();
    ModelLoadingType modelLoadingType = NetworkClient::getMessageFromServer<ModelLoadingType>();
    int dataSize = NetworkClient::getMessageFromServer<int>();
    QByteArray receivedData = NetworkClient::getMessageFromServer<QByteArray>(dataSize);
    QSharedPointer<QStandardItemModel> model = Serializer::deserializationDataModel(receivedData);

    return QSharedPointer<ModelData>(new ModelData{modeltype, modelLoadingType, model});
}

void P_SendModel::setModel(QSharedPointer<ModelData> set)
{
    if(P_Authorization::adminW)
        P_Authorization::adminW->setModel(set);
    else if(P_Authorization::playerW)
        P_Authorization::playerW->setModel(set);

}

void P_SendModel::initMapTableNames()
{
    tableNames.insert(ModelTypes::Users, "Users_pred");
    tableNames.insert(ModelTypes::ActiveTables, "ActiveTables_pred");
    tableNames.insert(ModelTypes::StuffUsers, "StuffUsers_pred");
    tableNames.insert(ModelTypes::Banlist, "Banlist_pred");
    tableNames.insert(ModelTypes::Credits, "Credits_pred");
    tableNames.insert(ModelTypes::Payments, "Payments_pred");
    tableNames.insert(ModelTypes::Profit, "Profit_pred");
}

const QString& P_SendModel::getTableName(ModelTypes modelType)
{
    if (tableNames.size() == 0)
        initMapTableNames();

    return tableNames[modelType];
}
