#ifndef BLACKJECKBACKGTOUND_H
#define BLACKJECKBACKGTOUND_H

#include <QWidget>
#include <QPainter>
#include <QPropertyAnimation>
#include <QTimer>
#include <QLabel>
//#include "Users/player.h"
#include "Games/card.h"
#include "Utils/notificationutil.h"

namespace Ui {
class BlackJeckBackground;
}

class BlackJeckBackground : public QWidget
{
    Q_OBJECT
    Ui::BlackJeckBackground *ui;
    QMap<int, QLabel*> placeCardOnTable;
    int numMovePlayer;

public:
    explicit BlackJeckBackground(QWidget *parent = nullptr);
    ~BlackJeckBackground();

    void movingCard(Card card);
    void movingFaceCard(QRect playerPosition);

private:
    void assigningValues();
    void resizeEvent(QResizeEvent* event) override;
    void paintEvent(QPaintEvent* event) override;
};

#endif // BLACKJECKBACKGTOUND_H
