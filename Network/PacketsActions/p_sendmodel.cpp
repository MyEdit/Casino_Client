#include "p_sendmodel.h"

QStandardItemModel* P_SendModel::getModelFromServer()
{
    ModelTypes modeltype;
    QByteArray receivedData;
    int dataSize;

    recv(NetworkClient::serverSocket, reinterpret_cast<char*>(&modeltype), sizeof(ModelTypes), 0);
    recv(NetworkClient::serverSocket, reinterpret_cast<char*>(&dataSize), sizeof(int), 0);
    receivedData.resize(dataSize);
    recv(NetworkClient::serverSocket, receivedData.data(), dataSize, 0);

    return Serializer::deserializationDataModel(receivedData);
}

