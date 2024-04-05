#ifndef TABLE_H
#define TABLE_H

#include <QSharedPointer>
#include <QList>
#include "Games/gamer.h"
#include "Games/Tabel/game.h"
#include "Users/player.h"

//Перенеси бы в отдельный файл
struct TableSettings
{
    int ID;
    double minBet;
    double stepBet;
    double minBalance;

    QByteArray serializeTableSettings() const
    {
        QByteArray data;
        QDataStream stream(&data, QIODevice::WriteOnly);
        stream << ID << minBet << stepBet << minBalance;
        return data;
    }

    static TableSettings deserializeTableSettings(const QByteArray& data)
    {
        QDataStream stream(data);
        TableSettings settings;
        stream >> settings.ID >> settings.minBet >> settings.stepBet >> settings.minBalance;
        return settings;
    }
};

class Table
{
    static QList<QSharedPointer<Table>> tables;

    Game game{};
    TableSettings tableSettings{};
    QList<QSharedPointer<Player>> playes{};

public:
    Table(Game game, TableSettings tableSettings);

    //GETTERS
    TableSettings getSettings();
    Game getGame();
    static QList<QSharedPointer<Table>> getTables();
    static void addTables(QSharedPointer<Table> table);

    //METHODS
    bool canPlayerJoin(QSharedPointer<Player>);
    bool canStartGame();
    void startGame();
    void joinPlayer(Player player);
    void leavePlayer(Player player);
    QByteArray serializeTable();
    static QSharedPointer<Table> deserializeTable(const QByteArray& data);
};

#endif // TABLE_H
