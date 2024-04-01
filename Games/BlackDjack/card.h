#ifndef CARD_H
#define CARD_H

#include "Games/BlackDjack/cardRank.h"
#include "Games/BlackDjack/cardSuit.h"
#include <QString>

class Card
{
    CardRank _rank;
    CardSuit _suit;

public:
    Card(CardRank rank, CardSuit suit);
    Card(QString card);

    int value() const;
    CardRank getRank() const;
    CardSuit getSuit() const;
    CardSuit convertToSuit(const QString& card);
    CardRank convertToRank(const QString& card);

    bool operator < (const Card& card) const
    {
        if (_rank == card._rank)
            return _suit < card._suit;
        else
            return _rank < card._rank;
    }

    bool operator == (const Card& card) const
    {
        bool rank = _rank == card._rank;
        bool suit = _suit == card._suit;

        return rank and suit;
    }
};

#endif // CARD_H
