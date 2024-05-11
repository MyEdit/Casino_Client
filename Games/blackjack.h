#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "Games/Tabel/game.h"
#include "QSharedPointer"
#include "Games/BlackDjack/GUI/blacljackwidget.h"

class BlaclJackWidget;
class BaseClassGameWidget;

class BlackJack : public Game
{
    Q_OBJECT
    int maximumScore = 21;

public:
    //Constructors
    BlackJack() {}
    BlackJack(int idTable, const QString& name);
    BlackJack(int idTable, QSharedPointer<QByteArray> data);

    //Methods
    bool isBust(); //Проверка перебора
    void createGUI() override;
    int getPlayerScore();

private:
    void renderTakeCard(QSharedPointer<Card> card) override;
};

#endif // BLACKJACK_H
