#ifndef BASECLASSGAMEWIDGET_H
#define BASECLASSGAMEWIDGET_H

#include <QWidget>
#include "Games/card.h"
#include "Users/player.h"
#include "Games/InterfaceElements/playersiconswidget.h"

class Player;
class PlayersIconsWidget;

class BaseClassGameWidget : public QWidget
{
    Q_OBJECT
protected:
    QSharedPointer<PlayersIconsWidget> playersIcons;
    QTimer* timerCheckTable;
    ModelTypes model;

public:
    explicit BaseClassGameWidget(QWidget *parent = nullptr) : QWidget(parent) {}

    virtual void updateProcessing(const QString& data) = 0;
    virtual void renderTakeCard(QSharedPointer<Card> card) = 0;
    virtual void renderFakeTakeCard(const QString& nickname) = 0;
    virtual void blocingInterface(bool flag) = 0;
    virtual void updatePlayersIcons(QList<QSharedPointer<Player>> playes);
    virtual void updateTimer(const QString& time) = 0;
    virtual void setMyScore(int score);
    virtual void clearCardOnTable() = 0;

protected:
    virtual void takeCard();
    virtual void pass();
    virtual void startChekedTable();
    virtual void checkTableExistence();
    virtual void distributor(QSharedPointer<QueryData> data);
    void changeEvent(QEvent *event) override;
    void showEvent(QShowEvent* event) override;
    void closeEvent(QCloseEvent* event) override;

protected slots:
    virtual void finished(bool isWin);
    virtual void insufficientBalance();
};

#endif // BASECLASSGAMEWIDGET_H
