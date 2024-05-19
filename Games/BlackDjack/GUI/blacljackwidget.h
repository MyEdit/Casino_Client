#ifndef BLACLJACKWIDGET_H
#define BLACLJACKWIDGET_H

#include <QWidget>
#include <QTimer>
#include "Games/BlackDjack/GUI/InterfaceElements/blackjackbackground.h"
#include "Games/card.h"
#include "Users/player.h"
#include "Games/blackjack.h"
#include "BaseClass/baseclassgamewidget.h"

class Player;

namespace Ui {
class BlaclJackWidget;
}

class BlaclJackWidget : public BaseClassGameWidget
{
    Q_OBJECT
    Ui::BlaclJackWidget *ui;
    QSharedPointer<BlackJackBackground> background;

public:
    explicit BlaclJackWidget(QWidget *parent = nullptr);
    ~BlaclJackWidget();

private:
    void renderTakeCard(QSharedPointer<Card> card) override;
    void renderFakeTakeCard(const QString& nickname) override;
    void updateProcessing(const QString& data) override;
    void blocingInterface(const bool flag) override;

    void rendering();
    void renderingTable();
    void renderingPlayersIcons();
    void resizeEvent(QResizeEvent *event) override;
    void connects();
    void updateTimer(const QString& time) override;
    void clearCardOnTable() override;

private slots:
    void finished(bool isWin) override;

private:
    friend class BlackJack;
};

#endif // BLACLJACKWIDGET_H
