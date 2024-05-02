#include "game.h"


Game::Game(const QString nameGame)
{
    this->nameGame = nameGame;
}

const QString& Game::getName()
{
    return nameGame;
}

QSharedPointer<QByteArray> Game::serializeGame()
{
    QSharedPointer<QByteArray> data(new QByteArray());
    QDataStream stream(&*data, QIODevice::WriteOnly);
    stream << nameGame;
    return data;
}

void Game::setGameName(const QString& nameGame)
{
    this->nameGame = nameGame;
}

bool Game::canJoin()
{

}

bool Game::canStartGame()
{

}

void Game::startGame()
{

}

void Game::leave()
{
    PacketTypes packettype = PacketTypes::P_PlayerLeaveTable;
    NetworkClient::sendToServer(&packettype, sizeof(PacketTypes));
    NetworkClient::sendToServer(&idTable, sizeof(int));

    WindowTracker::activeWindow->setEnabled(true);
}
