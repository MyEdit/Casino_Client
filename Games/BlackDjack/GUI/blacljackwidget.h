﻿#ifndef BLACLJACKWIDGET_H
#define BLACLJACKWIDGET_H

#include <QWidget>
#include <QTimer>
#include "Games/BlackDjack/GUI/InterfaceEements/blackjeckbackground.h"
#include "Games/BlackDjack/GUI/InterfaceEements/playersiconswidget.h"
#include "Network/PacketsActions/p_authorization.h"
#include "Games/card.h"
#include "Games/Tabel/table.h"

class PlayersIconsWidget;

namespace Ui {
class BlaclJackWidget;
}

class BlaclJackWidget : public QWidget
{
    Q_OBJECT
    Ui::BlaclJackWidget *ui;
    QSharedPointer<BlackJeckBackground> background;
    QSharedPointer<PlayersIconsWidget> playersIcons;
    QSharedPointer<Table> table;

public:
    explicit BlaclJackWidget(QSharedPointer<Table> table, QWidget *parent = nullptr);
    ~BlaclJackWidget();

    void updatePlayersIcons(QList<QSharedPointer<Player>> playes);
    void renderTakeCard(QSharedPointer<Card> card);
    void renderFakeTakeCard(const QString& nicname);
    void updateProcessing(const QString& data);
    void blocingInterface(const bool flag);

private:
    void rendering();
    void renderingTable();
    void renderingPlayersIcons();
    void resizeEvent(QResizeEvent *event) override;
    void connects();
    void takeCard();
    void doNotTakeCard();
    void showEvent(QShowEvent* event) override;
    void closeEvent(QCloseEvent* event) override;
    void updateTimer(const QString& time);
};

#endif // BLACLJACKWIDGET_H
