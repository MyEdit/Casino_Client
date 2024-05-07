#ifndef P_UPDATEBALANCE_H
#define P_UPDATEBALANCE_H

#include "Network/networkclient.h"

class P_UpdateBalance
{
public:
    static void updatePlayerBalance(double newBalance);
    static double getNewBalance();
};

#endif // P_UPDATEBALANCE_H
