#ifndef PLAYER_H
#define PLAYER_H

#include "Users/user.h"
#include "Games/BlackDjack/GUI/blacljackwidget.h"

class BlaclJackWidget;

class Player : public User
{
    double balance{};
    BlaclJackWidget* tableGUI;
    QVector<QSharedPointer<Card>> cardsInHand;

public:
    Player(int ID, const QString& name, double balance, const QString& login, Roles role);
    Player(const QByteArray& data);
    Player() {};

    void setTableGUI(BlaclJackWidget* tableGUI);

    //GETTERS
    int getID() override;
    const QString& getName() override;
    const QString& getLogin() override;
    Roles getRole() override;
    double getBalance();
    QSharedPointer<QByteArray> getPhoto() override;
    BlaclJackWidget* getTableGUI();
    QVector<QSharedPointer<Card>> getHand();
    QSharedPointer<Card> getCardInHand(int index);

    //METHODS
    QSharedPointer<QByteArray> serializeUser() override;
    void addCardInHand(QSharedPointer<Card> card);
};

#endif // PLAYER_H
