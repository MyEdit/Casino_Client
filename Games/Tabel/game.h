#ifndef GAME_H
#define GAME_H

#include <QString>
#include <QSharedPointer>
#include <QDataStream>
#include <QIODevice>

class Game
{
    QString nameGame{};

public:
    Game();
    Game(QString nameGame);

    QString getNameGame();

    QByteArray serializeGame();
    static QSharedPointer<Game> deserializeGame(const QByteArray& data);
};

#endif // GAME_H
