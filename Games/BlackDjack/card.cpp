#include "card.h"
#include <QStringList>

Card::Card(CardRank rank, CardSuit suit)
    : _rank{ rank }, _suit{ suit } {}

Card::Card(QString card)
{
    _rank = convertToRank(card);
    _suit = convertToSuit(card);
}

CardRank Card::convertToRank(const QString& card)
{
    QChar separator = '/';
    QStringList parts;
    parts = card.split(separator);
    QString rank = parts[1];
    CardRank cardRank{};

    if(rank == "2.png")
        cardRank = CardRank::RANK_2;
    else if(rank == "3.png")
        cardRank = CardRank::RANK_3;
    else if(rank == "4.png")
        cardRank = CardRank::RANK_4;
    else if(rank == "5.png")
        cardRank = CardRank::RANK_5;
    else if(rank == "6.png")
        cardRank = CardRank::RANK_6;
    else if(rank == "7.png")
        cardRank = CardRank::RANK_7;
    else if(rank == "8.png")
        cardRank = CardRank::RANK_8;
    else if(rank == "9.png")
        cardRank = CardRank::RANK_9;
    else if(rank == "10.png")
        cardRank = CardRank::RANK_10;
    else if(rank == "J.png")
        cardRank = CardRank::RANK_JACK;
    else if(rank == "Q.png")
        cardRank = CardRank::RANK_QUEEN;
    else if(rank == "K.png")
        cardRank = CardRank::RANK_KING;
    else if(rank == "A.png")
        cardRank = CardRank::RANK_ACE;

    return cardRank;
}

CardSuit Card::convertToSuit(const QString& card)
{
    QChar separator = '/';
    QStringList parts;
    parts = card.split(separator);
    QString suit = parts[0];
    CardSuit cardSuit{};

    if(suit == "Clubs")
        cardSuit = CardSuit::SUIT_CLUB;
    else if(suit == "Diamonds")
        cardSuit = CardSuit::SUIT_DIAMOND;
    else if(suit == "Hearts")
        cardSuit = CardSuit::SUIT_HEART;
    else if(suit == "Spades")
        cardSuit = CardSuit::SUIT_SPADE;

    return cardSuit;
}

int Card::value() const
{
    if (_rank <= CardRank::RANK_10)
        return (static_cast<int>(_rank) + 2);

    switch (_rank)
    {
    case CardRank::RANK_JACK:
    case CardRank::RANK_QUEEN:
    case CardRank::RANK_KING:
        return 10;
    case CardRank::RANK_ACE:
        return 11;
    default:
        return 0;
    }
}

CardRank Card::getRank() const
{
    return _rank;
}

CardSuit Card::getSuit() const
{
    return _suit;
}

