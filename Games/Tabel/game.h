﻿#ifndef GAME_H
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
    Q_OBJECT

protected:
    int idTable;
    QString nameGame{};
    int minPlayers{2};
    QWidget* menu;
    BaseClassGameWidget* GUI {};

    enum class GamePackets
    {
        P_TakeCard,
        P_TakeCardAnotherPlayer,
        P_PassMove,
        P_StartMove,
        P_Win,
        P_Lose
    };

public:
    Game() {}
    Game(const QString nameGame);

    const QString& getName();
    virtual BaseClassGameWidget* getGUI();
    virtual QSharedPointer<QByteArray> serializeGame();
    virtual void updatePlayersIcons(QList<QSharedPointer<Player>> players);
    virtual void takeCard();
    virtual void pass();
    virtual void onGamePacketReceived();
    virtual void onUpdateGameProcessing(const QString& data);

    virtual void createGUI() = 0;

    void setGameName(const QString& nameGame);
    void setMenu(QWidget* menu);
    void leave();
    int getTableID();

protected:
    virtual void setConnects();
    virtual void onUpdateGameTimer(const QString& data); //Когда обновляется таймер
    virtual void onTakeCard(); //Когда текущий игрок взял карту
    virtual void onTakeCardAnotherPlayer(); //Когда другой игрок взял карту
    virtual void onStartMove(); //Когда игрок может совершить ход
    virtual void onGameFinished(bool isWin);

    virtual void renderTakeCard(QSharedPointer<Card> card);
    virtual void renderTakeCardAnotherPlayer(const QString &nicname);
    virtual void unlockInterface(const QString &nickname);
    virtual void turn(GamePackets gamePacket);

signals:
    void signalTakeCard(const QSharedPointer<Card>);
    void signalTakeCardAnotherPlayer(const QString &nicname);
    void signalStartMove(const QString &nicname);
};

#endif // GAME_H
