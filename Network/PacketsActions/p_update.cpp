#include "p_update.h"

ModelTypes P_Update::getModelFromServer()
{
    return NetworkClient::getMessageFromServer<ModelTypes>();
}

void P_Update::updateTable(ModelTypes modelType)
{
    if(P_Authorization::adminW)
        P_Authorization::adminW->updateTable(modelType);
    else if(P_Authorization::playerW)
        P_Authorization::playerW->updateTable(modelType);
}
