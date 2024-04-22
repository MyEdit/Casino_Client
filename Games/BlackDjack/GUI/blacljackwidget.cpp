﻿#include "blacljackwidget.h"
#include "ui_blacljackwidget.h"

BlaclJackWidget::BlaclJackWidget(QSharedPointer<Table> table, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BlaclJackWidget),
    table(table)
{
    ui->setupUi(this);
    rendering();
    connects();
}

BlaclJackWidget::~BlaclJackWidget()
{
    delete ui;
}

void BlaclJackWidget::rendering()
{
    renderingTable();
    renderingPlayersIcons();

    for (int i = 0; i < ui->horizontalLayout_2->count(); i++)
    {
        QWidget* widget = ui->horizontalLayout_2->itemAt(i)->widget();
        if (widget)
            widget->hide();
    }
}

void BlaclJackWidget::renderingTable()
{
    background = QSharedPointer<BlackJeckBackground>(new BlackJeckBackground());
    ui->gridLayout->addWidget(background.get(), 0, 0, Qt::AlignCenter);
}

void BlaclJackWidget::renderingPlayersIcons()
{
    playersIcons = QSharedPointer<PlayersIconsWidget>(new PlayersIconsWidget);
    ui->gridLayout->addWidget(playersIcons.get(), 0, 0);
}

void BlaclJackWidget::resizeEvent(QResizeEvent* event)
{
    QWidget::resizeEvent(event);

    int w = width() / 1.3;
    int h = height() / 1.3;
    background->setFixedSize(w, h);
}

void BlaclJackWidget::renderTakeCard(Card card)
{
    background->movingCard(card);
}

void BlaclJackWidget::renderFakeTakeCard(QString nicname)
{
    for(QSharedPointer<PlayerIcon> playersIcon : playersIcons->getPlayerIcons())
    {
        if(playersIcon->getPlayer()->getName() == nicname)
            background->movingFaceCard(playersIcons->getRectPlayerIcon(playersIcon));
    }
}

void BlaclJackWidget::updatePlayersIcons(QList<QSharedPointer<Player>> playes)
{
    playersIcons->fullClearInfo();

    playersIcons->addPlayer(P_Authorization::getPlayer());

    for(QSharedPointer<Player> player : playes)
    {
        if(player->getLogin() != P_Authorization::getPlayer()->getLogin())
            playersIcons->addPlayer(player);
    }
}

void BlaclJackWidget::connects()
{
    connect(ui->buttonTakeCard, &QPushButton::clicked, this, &BlaclJackWidget::takeCard);
    connect(ui->buttonDoNotTakeCard, &QPushButton::clicked, this, &BlaclJackWidget::doNotTakeCard);
}

void BlaclJackWidget::takeCard()
{
    //TODO: послать запрос на взятие карты

    blocingInterface(false);
}

void BlaclJackWidget::doNotTakeCard()
{
    //TODO: послать запрос на скип хода

    blocingInterface(false);
}

void BlaclJackWidget::blocingInterface(bool flag)
{
    ui->buttonTakeCard->setEnabled(flag);
    ui->buttonDoNotTakeCard->setEnabled(flag);
}

void BlaclJackWidget::showEvent(QShowEvent* event)
{
    QWidget::showEvent(event);

    WindowTracker::activeWindow->setEnabled(false);
}

void BlaclJackWidget::closeEvent(QCloseEvent* event)
{
    QWidget::closeEvent(event);

    int idTable = table->getSettings().ID;
    PacketTypes packettype = PacketTypes::P_PlayerLeaveTable;
    NetworkClient::sendToServer(&packettype, sizeof(PacketTypes));
    NetworkClient::sendToServer(&idTable, sizeof(int));

    WindowTracker::activeWindow->setEnabled(true);
}

void BlaclJackWidget::updateTimer(int timerData)
{
    QString time{};
    if(timerData == -1)
        time = "Ожидание минималького кол-ва игроков...";
    else
        time = QString::number(timerData);

    if(timerData == 0)
    {
        for (int i = 0; i < ui->horizontalLayout_2->count(); i++)
        {
            QWidget* widget = ui->horizontalLayout_2->itemAt(i)->widget();
            if (widget)
                widget->show();
        }
        time = "Игра началась";
    }

    ui->labelGameProcess->setText(time);
}
