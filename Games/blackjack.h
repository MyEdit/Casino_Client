#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "Games/Tabel/game.h"
#include "QSharedPointer"
#include "Games/BlackDjack/GUI/blacljackwidget.h"

class BlaclJackWidget;
class BaseClassGameWidget;

//TODO: В общем нужно передать все так, чтобы Table был лишь прослойкой, неким интерфейсом, а большинство функционала перенести Game
class BlackJack : public Game
{
    //Наверное, игра должна знать в каком столе она находится и иметь связь Table <=> Game
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

    void createGUI() override;

//    //Methods
    void updatePlayersIcons(QList<QSharedPointer<Player>> players) override;
    void takeCard() override; //Запрос карты у сервера (GUI -> BlackJack::takeCard();)
    void pass() override;
    bool isBust(); //Проверка перебора
    int getPlayerScore();

//    //Events
    void onUpdateGameTimer(const QString& data) override; //Когда обновляется таймер
    void onTakeCard(QSharedPointer<Card> card) override; //Когда текущий игрок взял карту
    void onTakeCardAnotherPlayer(const QString& nicname) override; //Когда другой игрок взял карту
    void onStartMove() override; //Когда игрок может совершить ход
    void onUpdateGameProcessing(const QString& data) override;
    void onPlayerDefeat(QSharedPointer<Player> player) override; //Когда игрок проиграл
    void onGameFinished() override;
};

#endif // BLACKJACK_H
