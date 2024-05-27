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
    Q_OBJECT

protected:
    enum class GamePackets
    {
        P_TakeCard,
        P_TakeCardAnotherPlayer,
        P_PassMove,
        P_StartMove,
        P_Win,
        P_Lose
    };

    int idTable;
    QString nameGame{};
    int minPlayers{2};
    QWidget* menu;
    QSharedPointer<BaseClassGameWidget> GUI;
    QMap<GamePackets, std::function<void()>> gamePacketFunction;

public:
    Game();
    Game(const QString nameGame);

    const QString& getName();
    virtual QSharedPointer<BaseClassGameWidget> getGUI();
    virtual QSharedPointer<QByteArray> serializeGame();
    virtual void updatePlayersIcons(QList<QSharedPointer<Player>> players);
    virtual void takeCard();
    virtual void pass();
    virtual void onGamePacketReceived();
    virtual void onUpdateGameProcessing(const QString& data);

    virtual void createGUI();

    void setGameName(const QString& nameGame);
    void setMenu(QWidget* menu);
    void leave();
    int getTableID();

protected:
    virtual void setConnects();
    virtual void onTakeCard(); //Когда текущий игрок взял карту
    virtual void onTakeCardAnotherPlayer(); //Когда другой игрок взял карту
    virtual void onStartMove(); //Когда игрок может совершить ход
    virtual void onGameFinished(bool isWin);

    virtual void renderTakeCard(QSharedPointer<Card> card);
    virtual void renderTakeCardAnotherPlayer(const QString &nicname);
    virtual void turn(GamePackets gamePacket);

    void initPacketHandlerFunction();

signals:
    void signalTakeCard(const QSharedPointer<Card>);
    void signalTakeCardAnotherPlayer(const QString &nicname);
    void signalStartMove(const QString &nicname);
    void signalUpdateTimer(const QString &data);
    void signalUpdateProcessing(const QString &data);
    void signalBlocingInterface(const bool flag);
    void signalUpdatePlayersIcons(QList<QSharedPointer<Player> > players);
    void signalClearCardOnTable();
    void signalFinished(const bool isWin);
    void signalInsufficientBalance();
};

#endif // GAME_H
