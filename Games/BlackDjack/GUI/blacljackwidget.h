#ifndef BLACLJACKWIDGET_H
#define BLACLJACKWIDGET_H

#include <QWidget>
#include <QTimer>
#include "Games/BlackDjack/GUI/InterfaceElements/blackjackbackground.h"
#include "Games/InterfaceElements/playersiconswidget.h"
#include "Games/card.h"
#include "Users/player.h"
#include "Games/blackjack.h"
#include "BaseClass/baseclassgamewidget.h"

class PlayersIconsWidget;
class Player;

namespace Ui {
class BlaclJackWidget;
}

class BlaclJackWidget : public BaseClassGameWidget
{
    Q_OBJECT
    Ui::BlaclJackWidget *ui;
    QSharedPointer<BlackJackBackground> background;
    QSharedPointer<PlayersIconsWidget> playersIcons;
    QSharedPointer<BlackJack> game;

public:
    explicit BlaclJackWidget(QSharedPointer<BlackJack> game, QWidget *parent = nullptr);
    ~BlaclJackWidget();

private:
    void updatePlayersIcons(QList<QSharedPointer<Player>> playes) override;
    void renderTakeCard(QSharedPointer<Card> card) override;
    void renderFakeTakeCard(const QString& nicname) override;
    void updateProcessing(const QString& data) override;
    void blocingInterface(const bool flag) override;

    void rendering();
    void renderingTable();
    void renderingPlayersIcons();
    void resizeEvent(QResizeEvent *event) override;
    void connects();
    void showEvent(QShowEvent* event) override;
    void closeEvent(QCloseEvent* event) override;
    void updateTimer(const QString& time);
    void takeCard();
    void pass();

private:
    friend class BlackJack;
};

#endif // BLACLJACKWIDGET_H
