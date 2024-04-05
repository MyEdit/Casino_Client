#ifndef GAMER_H
#define GAMER_H

#include <vector>
#include <algorithm>
#include "Games/card.h"
#include "Games/deck.h"
#include <QString>

class Gamer
{
    std::vector<Card> _playerHand;
    int _score{};

public:
    Gamer() {};
    Gamer(Deck& deck, int numPlayers);

    int getNumCardsInHand() const;
    int score() const;
    int getScore();
    bool isBust() const;
    void sortHandBySuit();
    void removeCardFromHand(const Card& card);
    QString urlCard(Deck& deck);
    const Card& getCardInHand(int index) const;
    std::vector<Card> getCardsInHand();
};

#endif // GAMER_H
