#ifndef TABLE_H
#define TABLE_H

#include <QSharedPointer>
#include <QList>
#include "Games/gamer.h"
#include "Games/Tabel/game.h"
#include "Users/player.h"
#include "Network/PacketsActions/p_authorization.h"

//Перенеси бы в отдельный файл
struct TableSettings
{
    int ID;
    double minBet;
    double stepBet;
    double minBalance;
    int maxNumPlayer;

    QByteArray serializeTableSettings() const
    {
        QByteArray data;
        QDataStream stream(&data, QIODevice::WriteOnly);
        stream << ID << minBet << stepBet << minBalance << maxNumPlayer;
        return data;
    }

    static TableSettings deserializeTableSettings(const QByteArray& data)
    {
        QDataStream stream(data);
        TableSettings settings;
        stream >> settings.ID >> settings.minBet >> settings.stepBet >> settings.minBalance >> settings.maxNumPlayer;
        return settings;
    }
};

class Table
{
    Game game{};
    TableSettings tableSettings{};
    int currentNumPlayer;

public:
    Table(Game game, TableSettings tableSettings);
    Table(Game game, TableSettings tableSettings, int currentNumPlayer);

    static QList<QSharedPointer<Table>> tables;

    //GETTERS
    TableSettings getSettings();
    Game getGame();
    int getCurrentNumPlayer();
    static void addTable(QSharedPointer<Table> table);

    //METHODS
    bool canJoin();
    bool canStartGame();
    void startGame();
    void tryJoin();
    void leave();
    QByteArray serializeTable();
    static QSharedPointer<Table> deserializeTable(const QByteArray& data);
};

#endif // TABLE_H
