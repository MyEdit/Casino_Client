#include "p_startmove.h"

const QString P_StartMove::getMove()
{
    return NetworkClient::getMessageFromServer();
}

void P_StartMove::startMove(const QString& nickname)
{
    P_Authorization::getPlayer()->getGame()->onUpdateGameProcessing(nickname);
    P_Authorization::getPlayer()->getGame()->onStartMove();
}
