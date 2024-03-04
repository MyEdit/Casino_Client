#include "p_sendmodel.h"

QMap<ModelTypes, std::function<void(ModelData)>> P_SendModel::setModelFunctions;
QMap<ModelTypes, QString> P_SendModel::tableNames;

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
        P_Authorization::adminW->setModel_UsersTab(model);
    });

    setModelFunctions.insert(ModelTypes::ActiveTables, [&](ModelData model)
    {
        P_Authorization::adminW->setModel_ActiveTablesTab(model);
    });

    setModelFunctions.insert(ModelTypes::Banlist, [&](ModelData model)
    {
        P_Authorization::adminW->setModel_BanListTab(model);
    });

    setModelFunctions.insert(ModelTypes::StuffUsers, [&](ModelData model)
    {
        P_Authorization::adminW->setModel_StuffUsersTab(model);
    });

    setModelFunctions.insert(ModelTypes::Payments, [&](ModelData model)
    {
        P_Authorization::adminW->setModel_PaymentsTab(model);
    });

    setModelFunctions.insert(ModelTypes::Credits, [&](ModelData model)
    {
        P_Authorization::adminW->setModel_CreditsTab(model);
    });
}

void P_SendModel::initMapTableNames()
{
    tableNames.insert(ModelTypes::Users, "Users");
    tableNames.insert(ModelTypes::ActiveTables, "ActiveTables");
    tableNames.insert(ModelTypes::StuffUsers, "StuffUsers");
    tableNames.insert(ModelTypes::Banlist, "Banlist");
    tableNames.insert(ModelTypes::Credits, "Credits");
    tableNames.insert(ModelTypes::Payments, "Payments");
}

