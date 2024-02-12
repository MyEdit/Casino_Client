#ifndef PACKET_H
#define PACKET_H

//TODO: Переименовать класс или засунуть все перечисления в Constants.h

enum class PacketTypes
{
    P_Authorization,
    P_Notification,
    P_DeleteTable,
    P_AddTable,
    P_ConnectPlayerToTable,
    P_SendModel,
    P_SendTables,
    P_QueryWithoutResponce,
    P_Query
};

enum class ModelTypes
{
    Users,
    ExistingTables
};

enum class QueryTypes
{
    CountEntrites,  //колиество записей
    NumberRow,      //номер строки
    CreateEntry,    //Добавить запись
    UpdateEntry,    //Изменить запись
    DeleteEntry     //Удалить запись
};

#endif // PACKET_H
