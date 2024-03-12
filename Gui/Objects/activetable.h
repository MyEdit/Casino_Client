#ifndef ACTIVETABLE_H
#define ACTIVETABLE_H

#include <QString>

class ActiveTable
{
    int id {0};
    QString maxPlayers;
    QString numPlayers;
    QString minBet;
    QString betStep;
    QString minBalance;
    QString nameGame;

public:
    ActiveTable() {}
    ActiveTable(QString maxPlayers, QString numPlayers, QString minBet, QString betStep, QString minBalance, QString nameGame);
    ActiveTable(int id, QString maxPlayers, QString numPlayers, QString minBet, QString betStep, QString minBalance, QString nameGame);

    int getID();
    QString getMaxPlayers();
    QString getNumPlayers();
    QString getMinBet();
    QString getBetStep();
    QString getMinBalance();
    QString getNameGame();

    void setMaxPlayers(QString maxPlayers);
    void setNumPlayers(QString numPlayers);
    void setMinBet(QString minBet);
    void setBetStep(QString betStep);
    void setMinBalance(QString minBalance);
    void setNameGame(QString nameGame);

    bool inputDataIsValid();
};

#endif // ACTIVETABLE_H
