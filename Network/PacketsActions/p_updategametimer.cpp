#include "p_updategametimer.h"

int P_UpdateGameTimer::getTimerData()
{
    int timerData;
    recv(NetworkClient::serverSocket, reinterpret_cast<char*>(&timerData), sizeof(int), 0);
    return timerData;
}

void P_UpdateGameTimer::updateTimer(int timerData)
{
    P_Authorization::getPlayer()->getTableGUI()->updateTimer(timerData);
}
