#ifndef PACKET_H
#define PACKET_H

//TODO: Переименовать класс или засунуть все перечисления в Constants.h
#include <QStandardItemModel>

enum class PacketTypes
{
    P_Authorization,
    P_Notification,
    P_ConnectPlayerToTable,
    P_SendModel,
    P_SendTables,
    P_QueryWithoutResponce,
    P_Query,
    P_Reconnection
};

enum class ModelTypes
{
    Users,
    ActiveTables,
    StuffUsers,
    Banlist,
    Credits,
    Payments
};

enum class QueryTypes
{
    CountEntrites,  //колиество записей
    NumberRow,      //номер строки
    CreateEntry,    //Добавить запись
    UpdateEntry,    //Изменить запись
    DeleteEntry,    //Удалить запись
    Search          //Поиск
};

enum class ModelLoadingType
{
    Next,
    Central,
    Prev
};

enum class Roles
{
    None = -1,
    Admin = 1,
    TableManager = 2,
    User = 3,
};

struct ModelData
{
    ModelTypes modelTypes;
    ModelLoadingType modelLoadingType;
    QStandardItemModel* model;
};

struct QueryData
{
    ModelTypes modelTypes;
    QueryTypes queryTypes;
    QString result;
};

enum class WorkingWithDataType
{
    Add,
    Update
};

struct User
{
    Roles role;
    QString fullName;
};

#endif // PACKET_H
