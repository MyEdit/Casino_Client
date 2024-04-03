#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <algorithm>
#include "Games/card.h"
#include "Games/deck.h"
#include <QString>

class Player
{
    std::vector<Card> _playerHand;
    int _score{};

public:
    Player() {};
    Player(Deck& deck, int numPlayers);

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

#endif // PLAYER_H
