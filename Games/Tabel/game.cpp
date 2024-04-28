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
    turn(PacketTypes::P_PlayerLeaveTable);
    WindowTracker::activeWindow->setEnabled(true);
}

void Game::turn(const PacketTypes packetType)
{
    NetworkClient::sendToServer(&packetType, sizeof(PacketTypes));
    NetworkClient::sendToServer(&idTable, sizeof(int));
}
