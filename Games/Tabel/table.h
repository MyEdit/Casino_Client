#ifndef TABLE_H
#define TABLE_H

#include <QSharedPointer>
#include <QList>
#include <QMutex>
#include "Games/Tabel/game.h"
#include "Users/player.h"
#include "Network/PacketsActions/p_authorization.h"
#include "Games/BlackDjack/GUI/blacljackwidget.h"

class BlaclJackWidget;
class Player;

//Перенеси бы в отдельный файл
struct TableSettings
{
    int ID;
    double minBet;
    double stepBet;
    double minBalance;
    int maxCountPlayers;

    QByteArray serializeTableSettings() const
    {
        QByteArray data;
        QDataStream stream(&data, QIODevice::WriteOnly);
        stream << ID << minBet << stepBet << minBalance << maxCountPlayers;
        return data;
    }

    static TableSettings deserializeTableSettings(const QByteArray& data)
    {
        QDataStream stream(data);
        TableSettings settings;
        stream >> settings.ID >> settings.minBet >> settings.stepBet >> settings.minBalance >> settings.maxCountPlayers;
        return settings;
    }
};

class Table
{
    Game game{};
    TableSettings tableSettings{};
    QList<QSharedPointer<Player>> players{};
    static QList<QSharedPointer<Table>> tables;
    static QMutex accessTablesMutex;

public:
    Table(Game game, TableSettings tableSettings);
    Table(const QByteArray& data);

    //GETTERS
    TableSettings getSettings();
    Game getGame();
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
    QByteArray serializeTable();
    void openGameGUI();
    void updatePlayers();
    void setNewData(TableSettings tableSettings, Game game, QList<QSharedPointer<Player>> players);
};

#endif // TABLE_H
