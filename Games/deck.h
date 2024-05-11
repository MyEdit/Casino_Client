#ifndef DECK_H
#define DECK_H

#include <array>
#include <vector>
#include "card.h"

class Deck
{
    static constexpr int deckSize = 52;

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
