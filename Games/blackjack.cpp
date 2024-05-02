﻿#include "blackjack.h"

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

void BlackJack::setConnects()
{
    QObject::connect(this, &BlackJack::signalTakeCard, this, &BlackJack::renderTakeCard);
    QObject::connect(this, &BlackJack::signalTakeCardAnotherPlayer, this, &BlackJack::renderTakeCardAnotherPlayer);
    QObject::connect(this, &BlackJack::signalStartMove, this, &BlackJack::unlockInterface);
}

BlackJack::~BlackJack()
{
    if(GUI != nullptr)
        delete GUI;
}

BaseClassGameWidget *BlackJack::getGUI()
{
    return GUI;
}

void BlackJack::onGamePacketReceived()
{
    GamePackets gamePacket = NetworkClient::getMessageFromServer<GamePackets>();

    switch(gamePacket)
    {
        case(GamePackets::P_TakeCard):
        {
            this->onTakeCard();
            break;
        }
        case(GamePackets::P_TakeCardAnotherPlayer):
        {
            this->onTakeCardAnotherPlayer();
            break;
        }
        case(GamePackets::P_StartMove):
        {
            this->onStartMove();
            break;
        }
        default:
        {
            //Message::logWarn(new QString("[" + getName() + "] Client send unknown game packet"));
            break;
        }
    }
}

void BlackJack::onUpdateGameTimer(const QString& data)
{
    GUI->updateTimer(data);
}

void BlackJack::onTakeCard()
{
    CardRank cardRank = NetworkClient::getMessageFromServer<CardRank>();
    CardSuit cardSuit = NetworkClient::getMessageFromServer<CardSuit>();
    emit signalTakeCard(QSharedPointer<Card>(new Card(cardRank, cardSuit)));
}

void BlackJack::renderTakeCard(QSharedPointer<Card> card)
{
    GUI->renderTakeCard(card);
    P_Authorization::getPlayer()->addCardInHand(card);
    GUI->blocingInterface(true);
}

void BlackJack::onTakeCardAnotherPlayer()
{
    emit signalTakeCardAnotherPlayer(NetworkClient::getMessageFromServer());
}

void BlackJack::renderTakeCardAnotherPlayer(const QString& nicname)
{
    GUI->renderFakeTakeCard(nicname);
}

void BlackJack::onStartMove()
{
    emit signalStartMove(NetworkClient::getMessageFromServer());
}

void BlackJack::unlockInterface(const QString& nickname)
{
    P_Authorization::getPlayer()->getGame()->onUpdateGameProcessing(nickname);
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

//delete
void BlackJack::takeCard()
{
    this->turn(GamePackets::P_TakeCard);
    GUI->blocingInterface(false);
}

//delete
void BlackJack::pass()
{
    this->turn(GamePackets::P_PassMove);
    GUI->blocingInterface(false);
}

void BlackJack::turn(GamePackets gamePacket)
{
    PacketTypes packettype = PacketTypes::P_GamePacket;
    NetworkClient::sendToServer(&packettype, sizeof(PacketTypes));
    NetworkClient::sendToServer(&idTable, sizeof(int));
    NetworkClient::sendToServer(&gamePacket, sizeof(GamePackets));
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

int BlackJack::getTableID()
{
    return idTable;
}
