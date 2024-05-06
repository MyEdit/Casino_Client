﻿#ifndef PLAYERICON_H
#define PLAYERICON_H

#include <QWidget>
#include <QPainter>
#include "Users/player.h"

class Player;

namespace Ui {
class PlayerIcon;
}

class PlayerIcon : public QWidget
{
    Q_OBJECT
    Ui::PlayerIcon *ui;
    QSharedPointer<Player> player;

public:
    explicit PlayerIcon(QWidget *parent = nullptr);
    ~PlayerIcon();

    void setPlayer(QSharedPointer<Player> player);
    const QSharedPointer<Player> getPlayer();
    void clearInfo();
    void setScrore(int score);

private:
    void settingInformation();
    void setImage();
};

#endif // PLAYERICON_H
