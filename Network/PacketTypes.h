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
    P_Reconnection,
    P_ConnectOtherPlayerToTable,
    P_PlayerLeaveTable,
    P_UpdateGameProcessing,
    P_TakeCard,
    P_PassMove,
    P_TakeCardAnotherPlayer,
    P_StartMove
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
    QSharedPointer<QStandardItemModel> model;
};

struct QueryData
{
    ModelTypes modelTypes;
    QueryTypes queryTypes;
    QString result;
};

struct UserData
{
    Roles role;
    QString fullName;
};

struct ResultSearchInModel
{
    QSharedPointer<QStandardItemModel> model;
    QModelIndex index;
    int currentPage;
};

#endif // PACKET_H
