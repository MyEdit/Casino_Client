#include "game.h"


Game::Game(QString nameGame)
{
    this->nameGame = nameGame;
}

QString Game::getNameGame()
{
    return nameGame;
}

void Game::getGUI()
{
    //TODO: нужно будет на основании названия игры определять какую GUI запускать
}


QByteArray Game::serializeGame()
{
    QByteArray data;
    QDataStream stream(&data, QIODevice::WriteOnly);
    stream << nameGame;
    return data;
}

QSharedPointer<Game> Game::deserializeGame(const QByteArray& data)
{
    QDataStream stream(data);
    QString nameGame;
    stream >> nameGame;
    return QSharedPointer<Game>(new Game(nameGame));
}
