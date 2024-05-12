#include "p_updategameprocessing.h"

const QString P_UpdateGameProcessing::getData()
{
    return NetworkClient::getMessageFromServer();;
}

void P_UpdateGameProcessing::updateGameProcessing(const QString& data)
{
    if(P_Authorization::getPlayer()->getGame())
        P_Authorization::getPlayer()->getGame()->onUpdateGameProcessing(data);
}
