#include "deck.h"
#include <random>
#include <ctime>
#include <algorithm>

Deck::Deck()
{
    auto suits = static_cast<index_type>(CardSuit::MAX_SUITS);
    auto ranks = static_cast<index_type>(CardRank::MAX_RANKS);

    for (index_type suit = 0; suit < suits; ++suit)
    {
        for (index_type rank = 0; rank < ranks; ++rank)
            _deck.push_back({ static_cast<CardRank>(rank), static_cast<CardSuit>(suit) });
    }
    shuffle();
}

void Deck::shuffle()
{
    static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
    std::shuffle(_deck.begin(), _deck.end(), mt);
}

const Card& Deck::dealCard()
{
    return _deck[_cardIndex++];
}
