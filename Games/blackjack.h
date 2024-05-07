#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "Games/Tabel/game.h"
#include "QSharedPointer"
#include "Games/BlackDjack/GUI/blacljackwidget.h"
#include "Games/BlackDjack/BlackJackGamePackets.h"

class BlaclJackWidget;
class BaseClassGameWidget;

//TODO: В общем нужно передать все так, чтобы Table был лишь прослойкой, неким интерфейсом, а большинство функционала перенести Game
class BlackJack : public Game
{
    Q_OBJECT

    BlaclJackWidget* GUI {};
    QList<QSharedPointer<Player>> players{};

public:
    //Constructors
    BlackJack() {}
    BlackJack(int idTable, const QString& name);
    BlackJack(int idTable, QSharedPointer<QByteArray> data);
    ~BlackJack();

    //Getters
    BaseClassGameWidget* getGUI() override;
    int getTableID() override;

    //Methods
    void updatePlayersIcons(QList<QSharedPointer<Player>> players) override;
    void takeCard() override; //Запрос карты у сервера (GUI -> BlackJack::takeCard();)
    void pass() override;
    bool isBust(); //Проверка перебора
    void createGUI() override;
    int getPlayerScore();

    //Events
    void onUpdateGameTimer(const QString& data) override; //Когда обновляется таймер
    void onTakeCard() override; //Когда текущий игрок взял карту
    void onTakeCardAnotherPlayer() override; //Когда другой игрок взял карту
    void onStartMove() override; //Когда игрок может совершить ход
    void onUpdateGameProcessing(const QString& data) override;
    void onPlayerDefeat(QSharedPointer<Player> player) override; //Когда игрок проиграл
    void onGameFinished(bool isWin) override;
    void onGamePacketReceived() override;

private:
    void renderTakeCard(QSharedPointer<Card> card);
    void setConnects();
    void renderTakeCardAnotherPlayer(const QString &nicname);
    void unlockInterface(const QString &nickname);
    void turn(GamePackets gamePacket);

signals:
    void signalTakeCard(const QSharedPointer<Card>);
    void signalTakeCardAnotherPlayer(const QString &nicname);
    void signalStartMove(const QString &nicname);
};

#endif // BLACKJACK_H
