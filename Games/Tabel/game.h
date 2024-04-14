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
    Game() {};
    Game(QString nameGame);

    QString getNameGame();
    void getGUI(); //TODO: нужен будет базовый класс для гуи каждой игры

    QByteArray serializeGame();
    static QSharedPointer<Game> deserializeGame(const QByteArray& data);
};

#endif // GAME_H
