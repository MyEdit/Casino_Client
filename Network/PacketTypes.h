#ifndef PACKET_H
#define PACKET_H

enum class PacketTypes
{
    P_Authorization,
    P_Notification,
    P_DeleteTable,
    P_AddTable,
    P_ConnectPlayerToTable,
    P_SendModel,
    P_SendTables
};

enum class ModelTypes
{
    Users,
    Tables
};

#endif // PACKET_H
