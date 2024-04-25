#include "p_query.h"

QSharedPointer<QueryData> P_Query::getResultFromServer()
{
    ModelTypes type;
    QueryTypes queryTypes;

    recv(NetworkClient::serverSocket, reinterpret_cast<char*>(&type), sizeof(ModelTypes), 0);
    recv(NetworkClient::serverSocket, reinterpret_cast<char*>(&queryTypes), sizeof(QueryTypes), 0);

    QString result = NetworkClient::getMessageFromServer();
    QSharedPointer<QueryData> answer (new QueryData{type, queryTypes, result});

    return answer;
}

