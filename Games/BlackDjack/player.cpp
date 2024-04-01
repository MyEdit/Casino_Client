#include "player.h"
#include "card.h"
#include "constant.h"
#include "urlcard.h"

Player::Player(Deck& deck, int numPlayers)
{
    int numPlayerCards = deckSize / numPlayers;
    for (int i = 0; i < numPlayerCards; i++)
        _playerHand.push_back(deck.dealCard());
}


void Player::m_sortHandBySuit()
{
    std::sort(_playerHand.begin(), _playerHand.end(), [](const Card &a, const Card &b) {
        if (static_cast<int>(a.getSuit()) < static_cast<int>(b.getSuit()))
            return true;
        else if (static_cast<int>(a.getSuit()) > static_cast<int>(b.getSuit()))
            return false;
        else
            return static_cast<int>(a.getRank()) < static_cast<int>(b.getRank());
    });;
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
    return  UrlCard::getUrlCard(card);
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

std::vector<Card> Player::getCardInHand()
{
    return _playerHand;
}
