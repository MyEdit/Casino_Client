#include "p_updatebalance.h"

void P_UpdateBalance::updatePlayerBalance(double newBalance)
{
    P_Authorization::getPlayer()->setBalance(newBalance);
    P_Authorization::playerW->setNewBalance(QString::number(newBalance));
}

double P_UpdateBalance::getNewBalance()
{
    return NetworkClient::getMessageFromServer<double>();
}
