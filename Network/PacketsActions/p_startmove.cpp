#include "p_startmove.h"

const QString P_StartMove::getMove()
{
    return NetworkClient::getMessageFromServer();
}

void P_StartMove::startMove(const QString& nickname)
{
    P_Authorization::getPlayer()->getTableGUI()->updateProcessing(nickname);
    P_Authorization::getPlayer()->getTableGUI()->blocingInterface(true);
}
