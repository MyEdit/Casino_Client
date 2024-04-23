#include "p_updategametimer.h"

QString P_UpdateGameTimer::getData()
{
    QString data = NetworkClient::getMessageFromServer();
    return data;
}

void P_UpdateGameTimer::updateProcessing(QString data)
{
    P_Authorization::getPlayer()->getTableGUI()->updateProcessing(data);
}
