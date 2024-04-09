#ifndef BLACKJECKTABLEWIDGET_H
#define BLACKJECKTABLEWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPropertyAnimation>
#include <QTimer>
#include <QLabel>
#include "Users/player.h"
#include "Games/card.h"
#include "Utils/notificationutil.h"

namespace Ui {
class BlackJeckTableWidget;
}

class BlackJeckTableWidget : public QWidget
{
    Q_OBJECT
    Ui::BlackJeckTableWidget *ui;
    QMap<int, QLabel*> placeCardOnTable;
    int numMovePlayer;

public:
    explicit BlackJeckTableWidget(QWidget *parent = nullptr);
    ~BlackJeckTableWidget();

    void movingCard(Card card);
    void movingFaceCard(QRect playerPosition);

private:
    void assigningValues();
    void resizeEvent(QResizeEvent* event) override;
    void paintEvent(QPaintEvent* event) override;
};

#endif // BLACKJECKTABLEWIDGET_H
