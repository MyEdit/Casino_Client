#ifndef DECK_H
#define DECK_H

#include <array>
#include <vector>
#include "card.h"
#include "Games/BlackDjack/constant.h"

class Deck
{
public:
    using array_type = std::array<Card, deckSize>;
    using index_type = array_type::size_type;

private:
    std::vector<Card> _deck;
    index_type _cardIndex{0};

public:
    Deck();

    void shuffle();
    const Card& dealCard();
};

#endif // DECK_H
