#include "blackjack.h"

BlackJack::BlackJack(int idTable, const QString& name)
{
    this->nameGame = name;
    this->idTable = idTable;
    GUI = QSharedPointer<BlaclJackWidget>(new BlaclJackWidget(QSharedPointer<BlackJack>(this)));
}

BlackJack::BlackJack(int idTable, QSharedPointer<QByteArray> data)
{
    QDataStream stream(*data);
    QString nameGame;
    stream >> nameGame;

    this->idTable = idTable;
    this->nameGame = nameGame;
}

BlackJack::~BlackJack()
{

}

QSharedPointer<BaseClassGameWidget> BlackJack::getGUI()
{
    return GUI;
}

void BlackJack::onUpdateGameTimer(const QString& data)
{
    GUI->updateTimer(data);
}

void BlackJack::onTakeCard(QSharedPointer<Card> card)
{
    GUI->renderTakeCard(card);
}

void BlackJack::onTakeCardAnotherPlayer(const QString& nicname)
{
    GUI->renderFakeTakeCard(nicname);
}

void BlackJack::onStartMove()
{
    GUI->blocingInterface(true);
}

void BlackJack::onUpdateGameProcessing(const QString& data)
{
    bool ok;
    data.toInt(&ok);
    if(ok)
        onUpdateGameTimer(data);
    else
        GUI->updateProcessing(data);
}

void BlackJack::onPlayerDefeat(QSharedPointer<Player> player)
{
    Q_UNUSED(player)
}

void BlackJack::onGameFinished()
{

}

void BlackJack::updatePlayersIcons(QList<QSharedPointer<Player>> players)
{
    GUI->updatePlayersIcons(players);
}

void BlackJack::takeCard()
{
    turn(PacketTypes::P_TakeCard);
    GUI->blocingInterface(false);
}

void BlackJack::pass()
{
    turn(PacketTypes::P_PassMove);
    GUI->blocingInterface(false);
}

bool BlackJack::isBust()
{

}

int BlackJack::getPlayerScore(QVector<QSharedPointer<Card>> card)
{
    Q_UNUSED(card)
}

void BlackJack::createGUI()
{
    GUI = QSharedPointer<BlaclJackWidget>(new BlaclJackWidget(QSharedPointer<BlackJack>(this)));
}
