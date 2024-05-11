#include "blackjack.h"

BlackJack::BlackJack(int idTable, const QString& name)
{
    this->nameGame = name;
    this->idTable = idTable;
    GUI = QSharedPointer<BlaclJackWidget>(new BlaclJackWidget(QSharedPointer<BlackJack>(this)));
    setConnects();
}

BlackJack::BlackJack(int idTable, QSharedPointer<QByteArray> data)
{
    this->idTable = idTable;
    this->nameGame = QString::fromUtf8(*data);
    setConnects();
}

void BlackJack::renderTakeCard(QSharedPointer<Card> card)
{
    Game::renderTakeCard(card);

    if(isBust())
        pass();
    else
        GUI->blocingInterface(true);

    GUI->setMyScore(getPlayerScore());
}

bool BlackJack::isBust()
{
    return getPlayerScore() > maximumScore;
}

int BlackJack::getPlayerScore()
{
    int score{};
    for(QSharedPointer<Card> card : P_Authorization::getPlayer()->getHand())
        score += card->value();
    return score;
}

void BlackJack::createGUI()
{
    GUI = QSharedPointer<BlaclJackWidget>(new BlaclJackWidget(QSharedPointer<BlackJack>(this)));
}
