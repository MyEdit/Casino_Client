#include "activetable.h"

ActiveTable::ActiveTable(QString maxPlayers, QString numPlayers, QString minBet, QString betStep, QString minBalance, QString nameGame)
{
    this->maxPlayers = maxPlayers;
    this->numPlayers = numPlayers;
    this->minBet = minBet;
    this->betStep = betStep;
    this->minBalance = minBalance;
    this->nameGame = nameGame;
}

ActiveTable::ActiveTable(int id, QString maxPlayers, QString numPlayers, QString minBet, QString betStep, QString minBalance, QString nameGame)
{
    this->id = id;
    this->maxPlayers = maxPlayers;
    this->numPlayers = numPlayers;
    this->minBet = minBet;
    this->betStep = betStep;
    this->minBalance = minBalance;
    this->nameGame = nameGame;
}

int ActiveTable::getID()
{
    return id;
}

QString ActiveTable::getMaxPlayers()
{
    return maxPlayers;
}

QString ActiveTable::getNumPlayers()
{
    return numPlayers;
}

QString ActiveTable::getMinBet()
{
    return minBet;
}

QString ActiveTable::getBetStep()
{
    return betStep;
}

QString ActiveTable::getMinBalance()
{
    return minBet;
}

QString ActiveTable::getNameGame()
{
    return nameGame;
}

void ActiveTable::setMaxPlayers(QString maxPlayers)
{
    this->maxPlayers = maxPlayers;
}

void ActiveTable::setNumPlayers(QString numPlayers)
{
    this->numPlayers = numPlayers;
}

void ActiveTable::setMinBet(QString minBet)
{
    this->minBet = minBet;
}

void ActiveTable::setBetStep(QString betStep)
{
    this->betStep = betStep;
}

void ActiveTable::setMinBalance(QString minBalance)
{
    this->minBalance = minBalance;
}

void ActiveTable::setNameGame(QString nameGame)
{
    this->nameGame = nameGame;
}

bool ActiveTable::inputDataIsValid()
{
    for (QString value : {maxPlayers, minBet, betStep, minBalance, nameGame})
    {
        if (value.isEmpty())
            return false;
    }

    return true;
}
