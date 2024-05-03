#include "p_search.h"

QPair<ModelTypes, QString> P_Search::getResultSearchFromServer()
{
    ModelTypes type = NetworkClient::getMessageFromServer<ModelTypes>();
    QString result = NetworkClient::getMessageFromServer();
    return {type, result};
}
