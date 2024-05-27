#include "blackjack.h"

BlackJack::BlackJack(int idTable, const QString& name)
{
    this->nameGame = name;
    this->idTable = idTable;
    GUI = QSharedPointer<BlaclJackWidget>(new BlaclJackWidget());
    setConnects();
}

BlackJack::BlackJack(int idTable, QSharedPointer<QByteArray> data)
{
    this->idTable = idTable;
    this->nameGame = QString::fromUtf8(*data);
}

void BlackJack::renderTakeCard(QSharedPointer<Card> card)
{
    Game::renderTakeCard(card);

    if(isBust())
        pass();

    emit signalSetMyScore(getPlayerScore());
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
    GUI = QSharedPointer<BlaclJackWidget>(new BlaclJackWidget());
    QObject::connect(this, &BlackJack::signalSetMyScore, GUI.get(), &BaseClassGameWidget::setMyScore);
    Game::createGUI();
}
