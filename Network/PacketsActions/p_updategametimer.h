#ifndef P_UPDATEGAMETIMER_H
#define P_UPDATEGAMETIMER_H

#include "Network/networkclient.h"

class P_UpdateGameTimer
{
public:
    static QString getData();
    static void updateProcessing(QString data);
};

#endif // P_UPDATEGAMETIMER_H
