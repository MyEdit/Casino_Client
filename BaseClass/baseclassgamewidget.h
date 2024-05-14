#ifndef BASECLASSGAMEWIDGET_H
#define BASECLASSGAMEWIDGET_H

#include <QWidget>
#include "Games/card.h"
#include "Users/player.h"

class Player;

class BaseClassGameWidget : public QWidget
{
    Q_OBJECT
protected:
    QTimer* timerCheckTable;

    virtual void startChekedTable() = 0;
    virtual void checkTableExistence() = 0;
    virtual void distributor(QSharedPointer<QueryData> data) = 0;

public:
    explicit BaseClassGameWidget(QWidget *parent = nullptr) : QWidget(parent) {}

    virtual void updateProcessing(const QString& data) = 0;
    virtual void renderTakeCard(QSharedPointer<Card> card) = 0;
    virtual void renderFakeTakeCard(const QString& nickname) = 0;
    virtual void blocingInterface(bool flag) = 0;
    virtual void updatePlayersIcons(QList<QSharedPointer<Player>> playes) = 0;
    virtual void updateTimer(const QString& time) = 0;
    virtual void setMyScore(int score) = 0;
    virtual void clearCardOnTable() = 0;

protected slots:
    virtual void finished(bool isWin) = 0;
    virtual void insufficientBalance() = 0;
};

#endif // BASECLASSGAMEWIDGET_H
