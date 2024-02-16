#include "p_query.h"

QueryData* P_Query::getResultFromServer()
{
    ModelTypes type;
    recv(NetworkClient::serverSocket, reinterpret_cast<char*>(&type), sizeof(ModelTypes), 0);
    QString result = NetworkClient::getMessageFromServer();

    QueryData* answer = new QueryData{type, result};

    return answer;
}

