#ifndef BLACKJECKBACKGTOUND_H
#define BLACKJECKBACKGTOUND_H

#include <QWidget>
#include <QPainter>
#include <QPropertyAnimation>
#include <QTimer>
#include <QLabel>
#include "Games/card.h"
#include "Gui/Notification/notification.h"

#include "Utils/Message.h"

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
    void clearTable();
    void updateCardSize(int width, int height);

private:
    void assigningValues();

private slots:
    void movingCardInGuiThread(QSharedPointer<Card> card);
    void movingFaceInGuiThread(const QRect &playerPosition);
};

#endif // BLACKJECKBACKGTOUND_H
