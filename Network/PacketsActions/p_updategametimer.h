#ifndef P_UPDATEGAMETIMER_H
#define P_UPDATEGAMETIMER_H

#include "Network/networkclient.h"

class P_UpdateGameTimer
{
public:
    static int getTimerData();
    static void updateTimer(int timerData);
};

#endif // P_UPDATEGAMETIMER_H
