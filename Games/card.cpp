#include "card.h"
#include <QStringList>

QMap<Card, QString> Card::CardTextures = {
    {{CardRank::RANK_2, CardSuit::SUIT_CLUB},           ":/Standart/Clubs/Games/BlackDjack/assets/Standart/Clubs/2.png"},
    {{CardRank::RANK_3, CardSuit::SUIT_CLUB},           ":/Standart/Clubs/Games/BlackDjack/assets/Standart/Clubs/3.png"},
    {{CardRank::RANK_4, CardSuit::SUIT_CLUB},           ":/Standart/Clubs/Games/BlackDjack/assets/Standart/Clubs/4.png"},
    {{CardRank::RANK_5, CardSuit::SUIT_CLUB},           ":/Standart/Clubs/Games/BlackDjack/assets/Standart/Clubs/5.png"},
    {{CardRank::RANK_6, CardSuit::SUIT_CLUB},           ":/Standart/Clubs/Games/BlackDjack/assets/Standart/Clubs/6.png"},
    {{CardRank::RANK_7, CardSuit::SUIT_CLUB},           ":/Standart/Clubs/Games/BlackDjack/assets/Standart/Clubs/7.png"},
    {{CardRank::RANK_8, CardSuit::SUIT_CLUB},           ":/Standart/Clubs/Games/BlackDjack/assets/Standart/Clubs/8.png"},
    {{CardRank::RANK_9, CardSuit::SUIT_CLUB},           ":/Standart/Clubs/Games/BlackDjack/assets/Standart/Clubs/9.png"},
    {{CardRank::RANK_10, CardSuit::SUIT_CLUB},          ":/Standart/Clubs/Games/BlackDjack/assets/Standart/Clubs/10.png"},
    {{CardRank::RANK_JACK, CardSuit::SUIT_CLUB},        ":/Standart/Clubs/Games/BlackDjack/assets/Standart/Clubs/J.png"},
    {{CardRank::RANK_QUEEN, CardSuit::SUIT_CLUB},       ":/Standart/Clubs/Games/BlackDjack/assets/Standart/Clubs/Q.png"},
    {{CardRank::RANK_KING, CardSuit::SUIT_CLUB},        ":/Standart/Clubs/Games/BlackDjack/assets/Standart/Clubs/K.png"},
    {{CardRank::RANK_ACE, CardSuit::SUIT_CLUB},         ":/Standart/Clubs/Games/BlackDjack/assets/Standart/Clubs/A.png"},

    {{CardRank::RANK_2, CardSuit::SUIT_DIAMOND},        ":/Standart/Diamonds/Games/BlackDjack/assets/Standart/Diamonds/2.png"},
    {{CardRank::RANK_3, CardSuit::SUIT_DIAMOND},        ":/Standart/Diamonds/Games/BlackDjack/assets/Standart/Diamonds/3.png"},
    {{CardRank::RANK_4, CardSuit::SUIT_DIAMOND},        ":/Standart/Diamonds/Games/BlackDjack/assets/Standart/Diamonds/4.png"},
    {{CardRank::RANK_5, CardSuit::SUIT_DIAMOND},        ":/Standart/Diamonds/Games/BlackDjack/assets/Standart/Diamonds/5.png"},
    {{CardRank::RANK_6, CardSuit::SUIT_DIAMOND},        ":/Standart/Diamonds/Games/BlackDjack/assets/Standart/Diamonds/6.png"},
    {{CardRank::RANK_7, CardSuit::SUIT_DIAMOND},        ":/Standart/Diamonds/Games/BlackDjack/assets/Standart/Diamonds/7.png"},
    {{CardRank::RANK_8, CardSuit::SUIT_DIAMOND},        ":/Standart/Diamonds/Games/BlackDjack/assets/Standart/Diamonds/8.png"},
    {{CardRank::RANK_9, CardSuit::SUIT_DIAMOND},        ":/Standart/Diamonds/Games/BlackDjack/assets/Standart/Diamonds/9.png"},
    {{CardRank::RANK_10, CardSuit::SUIT_DIAMOND},       ":/Standart/Diamonds/Games/BlackDjack/assets/Standart/Diamonds/10.png"},
    {{CardRank::RANK_JACK, CardSuit::SUIT_DIAMOND},     ":/Standart/Diamonds/Games/BlackDjack/assets/Standart/Diamonds/J.png"},
    {{CardRank::RANK_QUEEN, CardSuit::SUIT_DIAMOND},    ":/Standart/Diamonds/Games/BlackDjack/assets/Standart/Diamonds/Q.png"},
    {{CardRank::RANK_KING, CardSuit::SUIT_DIAMOND},     ":/Standart/Diamonds/Games/BlackDjack/assets/Standart/Diamonds/K.png"},
    {{CardRank::RANK_ACE, CardSuit::SUIT_DIAMOND},      ":/Standart/Diamonds/Games/BlackDjack/assets/Standart/Diamonds/A.png"},

    {{CardRank::RANK_2, CardSuit::SUIT_HEART},          ":/Standart/Hearts/Games/BlackDjack/assets/Standart/Hearts/2.png"},
    {{CardRank::RANK_3, CardSuit::SUIT_HEART},          ":/Standart/Hearts/Games/BlackDjack/assets/Standart/Hearts/3.png"},
    {{CardRank::RANK_4, CardSuit::SUIT_HEART},          ":/Standart/Hearts/Games/BlackDjack/assets/Standart/Hearts/4.png"},
    {{CardRank::RANK_5, CardSuit::SUIT_HEART},          ":/Standart/Hearts/Games/BlackDjack/assets/Standart/Hearts/5.png"},
    {{CardRank::RANK_6, CardSuit::SUIT_HEART},          ":/Standart/Hearts/Games/BlackDjack/assets/Standart/Hearts/6.png"},
    {{CardRank::RANK_7, CardSuit::SUIT_HEART},          ":/Standart/Hearts/Games/BlackDjack/assets/Standart/Hearts/7.png"},
    {{CardRank::RANK_8, CardSuit::SUIT_HEART},          ":/Standart/Hearts/Games/BlackDjack/assets/Standart/Hearts/8.png"},
    {{CardRank::RANK_9, CardSuit::SUIT_HEART},          ":/Standart/Hearts/Games/BlackDjack/assets/Standart/Hearts/9.png"},
    {{CardRank::RANK_10, CardSuit::SUIT_HEART},         ":/Standart/Hearts/Games/BlackDjack/assets/Standart/Hearts/10.png"},
    {{CardRank::RANK_JACK, CardSuit::SUIT_HEART},       ":/Standart/Hearts/Games/BlackDjack/assets/Standart/Hearts/J.png"},
    {{CardRank::RANK_QUEEN, CardSuit::SUIT_HEART},      ":/Standart/Hearts/Games/BlackDjack/assets/Standart/Hearts/Q.png"},
    {{CardRank::RANK_KING, CardSuit::SUIT_HEART},       ":/Standart/Hearts/Games/BlackDjack/assets/Standart/Hearts/K.png"},
    {{CardRank::RANK_ACE, CardSuit::SUIT_HEART},        ":/Standart/Hearts/Games/BlackDjack/assets/Standart/Hearts/A.png"},

    {{CardRank::RANK_2, CardSuit::SUIT_SPADE},          ":/Standart/Spades/Games/BlackDjack/assets/Standart/Spades/2.png"},
    {{CardRank::RANK_3, CardSuit::SUIT_SPADE},          ":/Standart/Spades/Games/BlackDjack/assets/Standart/Spades/3.png"},
    {{CardRank::RANK_4, CardSuit::SUIT_SPADE},          ":/Standart/Spades/Games/BlackDjack/assets/Standart/Spades/4.png"},
    {{CardRank::RANK_5, CardSuit::SUIT_SPADE},          ":/Standart/Spades/Games/BlackDjack/assets/Standart/Spades/5.png"},
    {{CardRank::RANK_6, CardSuit::SUIT_SPADE},          ":/Standart/Spades/Games/BlackDjack/assets/Standart/Spades/6.png"},
    {{CardRank::RANK_7, CardSuit::SUIT_SPADE},          ":/Standart/Spades/Games/BlackDjack/assets/Standart/Spades/7.png"},
    {{CardRank::RANK_8, CardSuit::SUIT_SPADE},          ":/Standart/Spades/Games/BlackDjack/assets/Standart/Spades/8.png"},
    {{CardRank::RANK_9, CardSuit::SUIT_SPADE},          ":/Standart/Spades/Games/BlackDjack/assets/Standart/Spades/9.png"},
    {{CardRank::RANK_10, CardSuit::SUIT_SPADE},         ":/Standart/Spades/Games/BlackDjack/assets/Standart/Spades/10.png"},
    {{CardRank::RANK_JACK, CardSuit::SUIT_SPADE},       ":/Standart/Spades/Games/BlackDjack/assets/Standart/Spades/J.png"},
    {{CardRank::RANK_QUEEN, CardSuit::SUIT_SPADE},      ":/Standart/Spades/Games/BlackDjack/assets/Standart/Spades/Q.png"},
    {{CardRank::RANK_KING, CardSuit::SUIT_SPADE},       ":/Standart/Spades/Games/BlackDjack/assets/Standart/Spades/K.png"},
    {{CardRank::RANK_ACE, CardSuit::SUIT_SPADE},        ":/Standart/Spades/Games/BlackDjack/assets/Standart/Spades/A.png"}
};

QMap<QString, CardRank> Card::CardRangs = {
    {"2.png", CardRank::RANK_2},
    {"3.png", CardRank::RANK_3},
    {"4.png", CardRank::RANK_4},
    {"5.png", CardRank::RANK_5},
    {"6.png", CardRank::RANK_6},
    {"7.png", CardRank::RANK_7},
    {"8.png", CardRank::RANK_8},
    {"9.png", CardRank::RANK_9},
    {"10.png", CardRank::RANK_10},
    {"J.png", CardRank::RANK_JACK},
    {"Q.png", CardRank::RANK_QUEEN},
    {"K.png", CardRank::RANK_KING},
    {"A.png", CardRank::RANK_ACE}
};

QMap<QString, CardSuit> Card::CardSuits = {
    {"Clubs", CardSuit::SUIT_CLUB},
    {"Diamonds", CardSuit::SUIT_DIAMOND},
    {"Hearts", CardSuit::SUIT_HEART},
    {"Spades", CardSuit::SUIT_SPADE}
};

Card::Card(CardRank rank, CardSuit suit) :
    cardRank{ rank },
    cardSuit{ suit }
{

}

CardRank Card::convertToRank(const QString& card)
{
    QStringList parts = card.split('/');
    return CardRangs[parts[1]];
}

CardSuit Card::convertToSuit(const QString& card)
{
    QStringList parts = card.split('/');
    return CardSuits[parts[0]];
}

int Card::value() const
{
    if (cardRank <= CardRank::RANK_10)
        return (static_cast<int>(cardRank) + 2);

    switch (cardRank)
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

QString Card::getCardTexture(Card card)
{
    return CardTextures[card];
}

CardRank Card::getRank() const
{
    return cardRank;
}

CardSuit Card::getSuit() const
{
    return cardSuit;
}

