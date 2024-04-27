#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "Games/Tabel/game.h"
#include "QSharedPointer"
#include "Games/BlackDjack/GUI/blacljackwidget.h"

//TODO: В общем нужно передать все так, чтобы Table был лишь прослойкой, неким интерфейсом, а большинство функционала перенести Game
class BlackJack : Game
{
    //Наверное, игра должна знать в каком столе она находится и иметь связь Table <=> Game
    QSharedPointer<Table> table;
    BlaclJackWidget* GUI;
    QList<QSharedPointer<Player>> players{};

public:
    //Constructors
    BlackJack(QSharedPointer<Table> table, const QString& name)
    {
        this->nameGame = name;
        this->table = table;
        GUI = new BlaclJackWidget(this->table);
    }
    BlackJack();
    ~BlackJack()
    {
        delete GUI;
    }

    //Getters
//    QWidget* getGUI();

//    //Methods
//    bool canJoin();
//    bool canStartGame();
//    void startGame();
//    void leave();
//    void updatePlayers();
//    void takeCard(); //Запрос карты у сервера (GUI -> BlackJack::takeCard();)
//    void pass();
//    void turn(PacketTypes packetType);
//    bool isBust(); //Проверка перебора   //НЕ override
//    int getPlayerScore(QVector<QSharedPointer<Card>>); //НЕ override

//    //Events
//    void onUpdateGameTimer(const QString& data); //Когда обновляется таймер
//    void onTakeCard(QSharedPointer<Card> card); //Когда текущий игрок взял карту
//    void onTakeCardAnotherPlayer(); //Когда другой игрок взял карту
//    void onStartMove(const QString& nickname); //Когда игрок может совершить ход
//    void onUpdateGameProcessing(const QString& data);
//    void onPlayerDefeat(QSharedPointer<Player> player); //Когда игрок проиграл
//    void onGameFinished();
};

#endif // BLACKJACK_H
