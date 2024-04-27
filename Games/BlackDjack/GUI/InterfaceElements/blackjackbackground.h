#ifndef BLACKJECKBACKGTOUND_H
#define BLACKJECKBACKGTOUND_H

#include <QWidget>
#include <QPainter>
#include <QPropertyAnimation>
#include <QTimer>
#include <QLabel>
#include "Games/card.h"
#include "Utils/notificationutil.h"

namespace Ui {
class BlackJackBackground;
}

class BlackJackBackground : public QWidget
{
    Q_OBJECT
    Ui::BlackJackBackground *ui;
    QMap<int, QLabel*> placeCardOnTable;
    int numMovePlayer;

public:
    explicit BlackJackBackground(QWidget *parent = nullptr);
    ~BlackJackBackground();

    void movingCard(QSharedPointer<Card> card);
    void movingFaceCard(const QRect& playerPosition);

private:
    void assigningValues();
    void resizeEvent(QResizeEvent* event) override;
    void paintEvent(QPaintEvent* event) override;
};

#endif // BLACKJECKBACKGTOUND_H
