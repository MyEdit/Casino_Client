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
    Game(const QString nameGame);

    const QString& getName();
    void getGUI(); //TODO: нужен будет базовый класс для гуи каждой игры

    QSharedPointer<QByteArray> serializeGame();
    static QSharedPointer<Game> deserializeGame(QSharedPointer<QByteArray> data);
};

#endif // GAME_H
