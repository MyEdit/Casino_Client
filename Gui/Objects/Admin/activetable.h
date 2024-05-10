#ifndef ACTIVETABLE_H
#define ACTIVETABLE_H

#include <QString>

class ActiveTable
{
    int id {0};
    QString maxPlayers;
    QString minBet;
    QString betStep;
    QString minBalance;
    QString nameGame;

public:
    ActiveTable() {}
    ActiveTable(const QString& maxPlayers, const QString& minBet, const QString& betStep, const QString& minBalance, const QString& nameGame);
    ActiveTable(int id, const QString& maxPlayers, const QString& minBet, const QString& betStep, const QString& minBalance, const QString& nameGame);

    int getID();
    const QString& getMaxPlayers();
    const QString& getMinBet();
    const QString& getBetStep();
    const QString& getMinBalance();
    const QString& getNameGame();

    void setMaxPlayers(const QString& maxPlayers);
    void setMinBet(const QString& minBet);
    void setBetStep(const QString& betStep);
    void setMinBalance(const QString& minBalance);
    void setNameGame(const QString& nameGame);

    bool inputDataIsValid() const;
};

#endif // ACTIVETABLE_H
