#include "player.h"

Player::Player(int ID, const QString& name, double balance, const QString& login, Roles role)
{
    this->ID = ID;
    this->name = name;
    this->balance = balance;
    this->login = login;
    this->role = role;
}

Player::Player(const QByteArray& data)
{
    QDataStream stream(data);
    int ID;
    QString name, login;
    double balance;
    int roleInt;
    QByteArray photoData;
    stream >> ID >> name >> balance >> login >> roleInt >> photoData;
    Roles role = static_cast<Roles>(roleInt);

    this->ID = ID;
    this->name = name;
    this->balance = balance;
    this->login = login;
    this->role = role;
    this->photo = QSharedPointer<QByteArray>::create(photoData);
}

int Player::getID()
{
    return this->ID;
}

const QString& Player::getName()
{
    return this->name;
}
const QString& Player::getLogin()
{
    return this->login;
}

Roles Player::getRole()
{
    return this->role;
}

double Player::getBalance()
{
    return this->balance;
}

QSharedPointer<QByteArray> Player::getPhoto()
{
    return this->photo;
}

QSharedPointer<QByteArray> Player::serializeUser()
{
    QSharedPointer<QByteArray> byteArray(new QByteArray());
    QDataStream stream(&*byteArray, QIODevice::WriteOnly);
    stream << ID;
    stream << name;
    stream << balance;
    stream << login;
    stream << static_cast<int>(role);
    stream << photo;

    return byteArray;
}

void Player::setGame(QSharedPointer<Game> game)
{
    this->game = game;
}

QSharedPointer<Game> Player::getGame()
{
    return game;
}

void Player::addCardInHand(QSharedPointer<Card> card)
{
    cardsInHand.append(card);
}

void Player::clearCardsInHand()
{
    cardsInHand.clear();
}

void Player::setBalance(double newBalance)
{
    this->balance = newBalance;
}

QVector<QSharedPointer<Card>> Player::getHand()
{
    return cardsInHand;
}

QSharedPointer<Card> Player::getCardInHand(int index)
{
    if(index < cardsInHand.size())
        return cardsInHand[index];

    return nullptr;
}
