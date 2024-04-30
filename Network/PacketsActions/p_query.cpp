#include "p_query.h"

QSharedPointer<QueryData> P_Query::getResultFromServer()
{
    ModelTypes type = NetworkClient::getMessageFromServer<ModelTypes>();
    QueryTypes queryTypes = NetworkClient::getMessageFromServer<QueryTypes>();

    QString result = NetworkClient::getMessageFromServer();
    QSharedPointer<QueryData> answer (new QueryData{type, queryTypes, result});

    return answer;
}

