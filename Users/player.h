#ifndef PLAYER_H
#define PLAYER_H

#include "Users/user.h"
#include "Games/card.h"
#include "Games/Tabel/game.h"

class Game;

class Player : public User
{
    double balance{};
    QSharedPointer<Game> game;
    QVector<QSharedPointer<Card>> cardsInHand;

public:
    Player(int ID, const QString& name, double balance, const QString& login, Roles role);
    Player(const QByteArray& data);
    Player() {};

    void setGame(QSharedPointer<Game> game);

    //GETTERS
    int getID() override;
    const QString& getName() override;
    const QString& getLogin() override;
    Roles getRole() override;
    double getBalance();
    QSharedPointer<QByteArray> getPhoto() override;
    QSharedPointer<Game> getGame();
    QVector<QSharedPointer<Card>> getHand();
    QSharedPointer<Card> getCardInHand(int index);

    //METHODS
    QSharedPointer<QByteArray> serializeUser() override;
    void addCardInHand(QSharedPointer<Card> card);
    void clearCardsInHand();
};

#endif // PLAYER_H
