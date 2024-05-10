#include "activetable.h"
#include <QDebug>
ActiveTable::ActiveTable(const QString& maxPlayers, const QString& minBet, const QString& betStep, const QString& minBalance, const QString& nameGame)
{
    this->maxPlayers = maxPlayers;
    this->minBet = minBet;
    this->betStep = betStep;
    this->minBalance = minBalance;
    this->nameGame = nameGame;
}

ActiveTable::ActiveTable(int id, const QString& maxPlayers, const QString& minBet, const QString& betStep, const QString& minBalance, const QString& nameGame)
{
    this->id = id;
    this->maxPlayers = maxPlayers;
    this->minBet = minBet;
    this->betStep = betStep;
    this->minBalance = minBalance;
    this->nameGame = nameGame;
}

int ActiveTable::getID()
{
    return id;
}

const QString& ActiveTable::getMaxPlayers()
{
    return maxPlayers;
}

const QString& ActiveTable::getMinBet()
{
    return minBet;
}

const QString& ActiveTable::getBetStep()
{
    return betStep;
}

const QString& ActiveTable::getMinBalance()
{
    return minBalance;
}

const QString& ActiveTable::getNameGame()
{
    return nameGame;
}

void ActiveTable::setMaxPlayers(const QString& maxPlayers)
{
    this->maxPlayers = maxPlayers;
}

void ActiveTable::setMinBet(const QString& minBet)
{
    this->minBet = minBet;
}

void ActiveTable::setBetStep(const QString& betStep)
{
    this->betStep = betStep;
}

void ActiveTable::setMinBalance(const QString& minBalance)
{
    this->minBalance = minBalance;
}

void ActiveTable::setNameGame(const QString& nameGame)
{
    this->nameGame = nameGame;
}

bool ActiveTable::inputDataIsValid() const
{
    for (QString value : {maxPlayers, minBet, betStep, minBalance, nameGame})
    {
        if (value.isEmpty())
            return false;
    }

    return true;
}
