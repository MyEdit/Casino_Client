#include "p_sendmodel.h"

QMap<ModelTypes, std::function<void(ModelData)>> P_SendModel::setModelFunctions;

ModelData P_SendModel::getModelFromServer()
{
    ModelTypes modeltype;
    ModelLoadingType modelLoadingType;
    QByteArray receivedData;
    int dataSize;

    recv(NetworkClient::serverSocket, reinterpret_cast<char*>(&modeltype), sizeof(ModelTypes), 0);
    recv(NetworkClient::serverSocket, reinterpret_cast<char*>(&modelLoadingType), sizeof(ModelLoadingType), 0);
    recv(NetworkClient::serverSocket, reinterpret_cast<char*>(&dataSize), sizeof(int), 0);
    receivedData.resize(dataSize);
    recv(NetworkClient::serverSocket, receivedData.data(), dataSize, 0);

    QStandardItemModel* model = Serializer::deserializationDataModel(receivedData);
    return {modeltype, modelLoadingType, model};
}

void P_SendModel::setModel(ModelData set)
{
    ModelTypes modeltype = set.modelTypes;

    if (setModelFunctions.size() == 0)
        initMapFunctions();

    if (!setModelFunctions.contains(modeltype))
    {
        Message::logWarn("Unknown model type");
        return;
    }

    if(!P_Authorization::adminW)
        return;

    setModelFunctions[modeltype](set);
}

//Инициилизирует мапу ModelTypes -> Функция добавления модели
void P_SendModel::initMapFunctions()
{
    setModelFunctions.insert(ModelTypes::Users, [&](ModelData model)
    {
        P_Authorization::adminW->setModel_AllUsersTab(model);
    });
    setModelFunctions.insert(ModelTypes::ExistingTables, [&](ModelData model)
    {
        P_Authorization::adminW->setModel_ExistingTab(model);
    });
}
