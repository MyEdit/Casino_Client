#include "blackjack.h"

BlackJack::BlackJack(int idTable, const QString& name)
{
    this->nameGame = name;
    this->idTable = idTable;
    GUI = new BlaclJackWidget(QSharedPointer<BlackJack>(this));
    setConnects();
}

BlackJack::BlackJack(int idTable, QSharedPointer<QByteArray> data)
{
    this->idTable = idTable;
    this->nameGame = QString::fromUtf8(*data);
    setConnects();
}

BlackJack::~BlackJack()
{
    if(GUI != nullptr)
        delete GUI;
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
    GUI = new BlaclJackWidget(QSharedPointer<BlackJack>(this));
}
