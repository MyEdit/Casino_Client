#include "game.h"


Game::Game(const QString nameGame)
{
    this->nameGame = nameGame;
}

const QString& Game::getName()
{
    return nameGame;
}

void Game::getGUI()
{
    //TODO: нужно будет на основании названия игры определять какую GUI запускать
}


QSharedPointer<QByteArray> Game::serializeGame()
{
    QSharedPointer<QByteArray> data(new QByteArray());
    QDataStream stream(&*data, QIODevice::WriteOnly);
    stream << nameGame;
    return data;
}

QSharedPointer<Game> Game::deserializeGame(QSharedPointer<QByteArray> data)
{
    QDataStream stream(*data);
    QString nameGame;
    stream >> nameGame;
    return QSharedPointer<Game>(new Game(nameGame));
}
