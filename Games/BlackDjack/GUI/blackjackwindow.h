#ifndef BLACKDJACK_H
#define BLACKDJACK_H

#include <QMainWindow>
#include <QLabel>
#include <QMap>
#include "Games/deck.h"
#include "Games/player.h"
#include "Utils/windowtracker.h"

namespace Ui {
class BlackjackWindows;
}

class BlackjackWindows : public QMainWindow
{
    Q_OBJECT
    Ui::BlackjackWindows *ui;
    QString _nameGame;
    Deck* _deck;
    Player* _bot;
    Player* _player;
    int _numMovePlayer;
    int _numMoveBot;
    bool _fullScreen;
    QMap<int, QLabel*> _cardOnTablePlayer;
    QMap<int, QLabel*> _cardOnTableDiller;

public:
    explicit BlackjackWindows(QWidget *parent = nullptr);
    ~BlackjackWindows();

private:
    void botTurn();
    void takeKard();
    void enough();
    void changeEvent(QEvent *event);

private slots:
    void on_action_2_triggered();
    void on_action_triggered();
    void on_action_4_triggered();
};

#endif // BLACKDJACK_H
