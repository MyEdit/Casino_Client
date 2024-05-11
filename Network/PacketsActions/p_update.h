#ifndef P_UPDATE_H
#define P_UPDATE_H

#include "Network/PacketTypes.h"
#include "Network/networkclient.h"

class P_Update
{
public:
    static ModelTypes getModelFromServer();
    static void updateTable(ModelTypes modelType);
};

#endif // P_UPDATE_H
