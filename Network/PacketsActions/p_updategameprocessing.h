#ifndef P_UPDATEGAMEPROCESSING_H
#define P_UPDATEGAMEPROCESSING_H

#include "Network/networkclient.h"

class P_UpdateGameProcessing
{
public:
    static const QString getData();
    static void updateGameProcessing(const QString &data);
};

#endif // P_UPDATEGAMEPROCESSING_H
