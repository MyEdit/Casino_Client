#ifndef GAME_H
#define GAME_H

#include <QString>
#include <QSharedPointer>
#include <QDataStream>
#include <QIODevice>
#include "Network/networkclient.h"
#include "BaseClass/baseclassgamewidget.h"

class Player;
class BaseClassGameWidget;

class Game : public QObject
{
protected:
    int idTable;
    QString nameGame{};
    int minPlayers{2}; //У каждой игры свой минимальный лимит игроков для старта, пока вписываю тут. TODO: Нужен отдельный класс для игры BlackJack

public:
    Game() {}
    Game(const QString nameGame);

    const QString& getName();
    virtual QSharedPointer<BaseClassGameWidget> getGUI() = 0;

    virtual QSharedPointer<QByteArray> serializeGame();
    virtual void updatePlayersIcons(QList<QSharedPointer<Player>> players) = 0;
    virtual void createGUI() = 0;

public:
    //Methods
    bool canJoin();
    bool canStartGame();
    void startGame();
    void leave();
    virtual void takeCard() = 0; //Запрос карты у сервера (GUI -> BlackJack::takeCard();)
    virtual void pass() = 0;
    void turn(const PacketTypes packetType);

public:
    //Events
    virtual void onUpdateGameTimer(const QString& data) = 0; //Когда обновляется таймер
    virtual void onTakeCard(QSharedPointer<Card> card) = 0; //Когда текущий игрок взял карту
    virtual void onTakeCardAnotherPlayer(const QString& nicname) = 0; //Когда другой игрок взял карту
    virtual void onStartMove() = 0; //Когда игрок может совершить ход
    virtual void onUpdateGameProcessing(const QString& data) = 0;
    virtual void onPlayerDefeat(QSharedPointer<Player> player) = 0; //Когда игрок проиграл
    virtual void onGameFinished() = 0;
};

#endif // GAME_H
