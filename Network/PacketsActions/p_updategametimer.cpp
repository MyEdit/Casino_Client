#include "p_updategametimer.h"

void P_UpdateGameTimer::getTimerData()
{
    int timerData;
    recv(NetworkClient::serverSocket, reinterpret_cast<char*>(&timerData), sizeof(int), 0);
    Message::logInfo(timerData);
}
