#include "p_startmove.h"

QString P_StartMove::getMove()
{
    QString data = NetworkClient::getMessageFromServer();
    return data;
}

void P_StartMove::startMove(QString nickname)
{
    P_Authorization::getPlayer()->getTableGUI()->updateProcessing(nickname);
    P_Authorization::getPlayer()->getTableGUI()->blocingInterface(true);
}
