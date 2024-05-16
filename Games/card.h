#ifndef CARD_H
#define CARD_H

#include "Games/cardRank.h"
#include "Games/cardSuit.h"
#include <QString>
#include <QMap>
#include <QSharedPointer>

class Card
{
    CardRank cardRank;
    CardSuit cardSuit;

private:
    static QMap<Card, QString> CardTextures;
    static QMap<QString, CardRank> CardRangs;
    static QMap<QString, CardSuit> CardSuits;

public:
    Card(CardRank rank, CardSuit suit);

    int value() const;
    CardRank getRank() const;
    CardSuit getSuit() const;
    CardSuit convertToSuit(const QString& card);
    CardRank convertToRank(const QString& card);
    static QString getCardTexture(Card card);

    bool operator < (const Card& card) const
    {
        if (cardRank == card.cardRank)
            return cardSuit < card.cardSuit;
        else
            return cardRank < card.cardRank;
    }

    bool operator == (const Card& card) const
    {
        bool rank = cardRank == card.cardRank;
        bool suit = cardSuit == card.cardSuit;

        return rank and suit;
    }
};

#endif // CARD_H
