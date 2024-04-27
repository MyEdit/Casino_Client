#ifndef GAME_H
#define GAME_H

#include <QString>
#include <QSharedPointer>
#include <QDataStream>
#include <QIODevice>
#include "Network/networkclient.h"
#include "Games/Tabel/table.h"

class Player;
class Table;

class Game
{
protected:
    QSharedPointer<Table> table;
    QString nameGame{};
    int minPlayers{2}; //У каждой игры свой минимальный лимит игроков для старта, пока вписываю тут. TODO: Нужен отдельный класс для игры BlackJack

public:
    Game() {};
    Game(const QString nameGame);
    virtual ~Game() {}

    const QString& getName();
    void getGUI(); //TODO: нужен будет базовый класс для гуи каждой игры

    QSharedPointer<QByteArray> serializeGame();
    static QSharedPointer<Game> deserializeGame(QSharedPointer<QByteArray> data);

protected:
    bool canJoin();
    bool canStartGame();
    void startGame();
    void leave();
    void updatePlayersIcons(QList<QSharedPointer<Player>> playes);
    virtual void takeCard() {}; //Запрос карты у сервера (GUI -> BlackJack::takeCard();)
    virtual void pass() {};
    void turn(PacketTypes packetType);
};

#endif // GAME_H
