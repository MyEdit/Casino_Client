#ifndef PLAYER_H
#define PLAYER_H

#include "Users/user.h"
#include "Games/BlackDjack/GUI/blacljackwidget.h"

class BlaclJackWidget;

class Player : public User
{
    double balance{};
    BlaclJackWidget* tableGUI;

public:
    Player(int ID, QString name, double balance, QString login, Roles role);
    Player(const QByteArray& data);
    Player() {};

    void setTableGUI(BlaclJackWidget* tableGUI);

    //GETTERS
    int getID() override;
    QString getName() override;
    QString getLogin() override;
    Roles getRole() override;
    double getBalance();
    QByteArray getPhoto() override;
    BlaclJackWidget* getTableGUI();

    //METHODS
    QByteArray serializeUser() override;
};

#endif // PLAYER_H
