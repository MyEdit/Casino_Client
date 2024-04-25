#ifndef GAME_H
#define GAME_H

#include <QString>
#include <QSharedPointer>
#include <QDataStream>
#include <QIODevice>

class Game
{
protected:
    QString nameGame{};
    int minPlayers{2}; //У каждой игры свой минимальный лимит игроков для старта, пока вписываю тут. TODO: Нужен отдельный класс для игры BlackJack

public:
    Game() {};
    Game(QString nameGame);

    QString getName();
    void getGUI(); //TODO: нужен будет базовый класс для гуи каждой игры

    QByteArray serializeGame();
    static QSharedPointer<Game> deserializeGame(const QByteArray& data);
};

#endif // GAME_H
