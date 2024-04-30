﻿#include "p_takecard.h"

QSharedPointer<Card> P_TakeCard::takeCard()
{
    CardRank cardRank = NetworkClient::getMessageFromServer<CardRank>();
    CardSuit cardSuit = NetworkClient::getMessageFromServer<CardSuit>();
    return QSharedPointer<Card>(new Card(cardRank, cardSuit));
}

const QString P_TakeCard::takeCardAnotherPlayer()
{
    return NetworkClient::getMessageFromServer();
}

void P_TakeCard::renderTakeCard(QSharedPointer<Card> card)
{
    P_Authorization::getPlayer()->getGame()->onTakeCard(card);
    P_Authorization::getPlayer()->getGame()->onStartMove();
}

void P_TakeCard::renderTakeCardAnotherPlayer(const QString& nicname)
{
    P_Authorization::getPlayer()->getGame()->onTakeCardAnotherPlayer(nicname);
}
