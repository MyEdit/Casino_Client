#include "p_sendmodel.h"

QMap<ModelTypes, std::function<void(QStandardItemModel*)>> P_SendModel::setModelFunctions;

QPair<ModelTypes, QStandardItemModel *> P_SendModel::getModelFromServer()
{
    ModelTypes modeltype;
    QByteArray receivedData;
    int dataSize;

    recv(NetworkClient::serverSocket, reinterpret_cast<char*>(&modeltype), sizeof(ModelTypes), 0);
    recv(NetworkClient::serverSocket, reinterpret_cast<char*>(&dataSize), sizeof(int), 0);
    receivedData.resize(dataSize);
    recv(NetworkClient::serverSocket, receivedData.data(), dataSize, 0);

    QStandardItemModel* model = Serializer::deserializationDataModel(receivedData);
    return {modeltype, model};
}

void P_SendModel::setModel(QPair<ModelTypes, QStandardItemModel*> set)
{
    ModelTypes modeltype = set.first;
    QStandardItemModel* model = set.second;

    if (setModelFunctions.size() == 0)
        initMapFunctions();

    if (!setModelFunctions.contains(modeltype))
    {
        Message::logWarn("Unknown model type");
        return;
    }

    if(!P_Authorization::adminW)
        return;

    setModelFunctions[modeltype](model);
}

//Инициилизирует мапу ModelTypes -> Функция добавления модели
void P_SendModel::initMapFunctions()
{
    setModelFunctions.insert(ModelTypes::Users, [&](QStandardItemModel* model)
    {
        P_Authorization::adminW->setModel_AllUsersTab(model);
    });
    setModelFunctions.insert(ModelTypes::ExistingTables, [&](QStandardItemModel* model)
    {
        P_Authorization::adminW->setModel_ExistingTab(model);
    });
}
