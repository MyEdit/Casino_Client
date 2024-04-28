#ifndef TABLE_H
#define TABLE_H

#include <QSharedPointer>
#include <QList>
#include <QMutex>
#include "Users/player.h"
#include "Network/PacketsActions/p_authorization.h"
#include "Games/Tabel/game.h"

class Game;
class Player;
class BlackJack;

//TODO: Перенеси бы в отдельный файл
struct TableSettings
{
    int ID;
    double minBet;
    double stepBet;
    double minBalance;
    int maxCountPlayers;

    QSharedPointer<QByteArray> serializeTableSettings() const
    {
        QSharedPointer<QByteArray> data(new QByteArray());
        QDataStream stream(&*data, QIODevice::WriteOnly);
        stream << ID << minBet << stepBet << minBalance << maxCountPlayers;
        return data;
    }

    static TableSettings deserializeTableSettings(QSharedPointer<QByteArray> data)
    {
        QDataStream stream(*data);
        TableSettings settings;
        stream >> settings.ID >> settings.minBet >> settings.stepBet >> settings.minBalance >> settings.maxCountPlayers;
        return settings;
    }
};

class Table
{
    QSharedPointer<Game> game;
    TableSettings tableSettings{};
    QList<QSharedPointer<Player>> players{};
    static QList<QSharedPointer<Table>> tables;
    static QMutex accessTablesMutex;

public:
    Table(QSharedPointer<Game> game, TableSettings tableSettings);
    Table(const QByteArray& data);

    //GETTERS
    TableSettings getSettings();
    QSharedPointer<Game> getGame();
    int getCurrentNumPlayer();
    QList<QSharedPointer<Player>> getPlayers();
    static QSharedPointer<Table> getTable(int idTable);
    static QList<QSharedPointer<Table>>& getTabels();
    static void addTable(QSharedPointer<Table> table);

    //METHODS
    bool canJoin();
    bool canStartGame();
    void startGame();
    void tryJoin();
    void leave();
    QSharedPointer<QByteArray> serializeTable();
    void openGameGUI();
    void updatePlayers();
    void setNewData(TableSettings tableSettings, QSharedPointer<Game> game, QList<QSharedPointer<Player>> players);
};

#endif // TABLE_H
