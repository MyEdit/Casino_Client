#include "player.h"
#include "card.h"

Player::Player(Deck& deck, int numPlayers)
{
    int numPlayerCards = deckSize / numPlayers;
    for (int i = 0; i < numPlayerCards; i++)
        _playerHand.push_back(deck.dealCard());
}

void Player::sortHandBySuit()
{
    std::sort(_playerHand.begin(), _playerHand.end(), [](const Card &firstCard, const Card &nextCard) {
        if (static_cast<int>(firstCard.getSuit()) < static_cast<int>(nextCard.getSuit()))
            return true;

        if (static_cast<int>(firstCard.getSuit()) > static_cast<int>(nextCard.getSuit()))
            return false;

        return static_cast<int>(firstCard.getRank()) < static_cast<int>(nextCard.getRank());
    });
}

void Player::removeCardFromHand(const Card& card)
{
    auto it = std::find(_playerHand.begin(), _playerHand.end(), card);
    if (it != _playerHand.end())
        _playerHand.erase(it);
}

int Player::getNumCardsInHand() const
{
    return static_cast<int>(_playerHand.size());
}

const Card& Player::getCardInHand(int index) const
{
    return _playerHand[index];
}

QString Player::urlCard(Deck& deck)
{
    const Card card = deck.dealCard();
    if(card.value() == 11)
    {
        if(_score > 10)
            _score += 1;
        else
            _score += 11;
    }
    else
        _score += card.value();
    return  Card::getCardTexture(card);
}

int Player::score() const
{
    return _score;
}

bool Player::isBust() const
{
    return (_score > maximumScore);
}

int Player::getScore()
{
    return _score;
}

std::vector<Card> Player::getCardsInHand()
{
    return _playerHand;
}
