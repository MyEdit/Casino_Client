#include "p_takecard.h"

QSharedPointer<Card> P_TakeCard::takeCard()
{
    CardRank cardRank;
    CardSuit cardSuit;

    recv(NetworkClient::serverSocket, reinterpret_cast<char*>(&cardRank), sizeof(PacketTypes), 0);
    recv(NetworkClient::serverSocket, reinterpret_cast<char*>(&cardSuit), sizeof(PacketTypes), 0);

    return QSharedPointer<Card>(new Card(cardRank, cardSuit));
}

const QString P_TakeCard::takeCardAnotherPlayer()
{
    return NetworkClient::getMessageFromServer();
}

void P_TakeCard::renderTakeCard(QSharedPointer<Card> card)
{
    P_Authorization::getPlayer()->getTableGUI()->renderTakeCard(card);
    P_Authorization::getPlayer()->getTableGUI()->blocingInterface(true);
}

void P_TakeCard::renderTakeCardAnotherPlayer(const QString& nicname)
{
    P_Authorization::getPlayer()->getTableGUI()->renderFakeTakeCard(nicname);
}
