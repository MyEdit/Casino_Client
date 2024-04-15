#include "blacljackwidget.h"
#include "ui_blacljackwidget.h"

BlaclJackWidget::BlaclJackWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BlaclJackWidget)
{
    ui->setupUi(this);
    rendering();
}

BlaclJackWidget::~BlaclJackWidget()
{
    delete ui;
}

void BlaclJackWidget::rendering()
{
    renderingTable();
    renderingPlayersIcons();
}

void BlaclJackWidget::renderingTable()
{
    tabel = QSharedPointer<BlackJeckTableWidget>(new BlackJeckTableWidget());
    ui->gridLayout->addWidget(tabel.get(), 0, 0, Qt::AlignCenter);
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
    tabel->setFixedSize(w, h);
}

void BlaclJackWidget::renderTakeCard(Card card)
{
    tabel->movingCard(card);
}

void BlaclJackWidget::renderFakeTakeCard(QString nicname)
{
    for(QSharedPointer<PlayerIcon> playersIcon : playersIcons->getPlayerIcons())
    {
        if(playersIcon->getPlayer()->getName() == nicname)
            tabel->movingFaceCard(playersIcons->getRectPlayerIcon(playersIcon));
    }
}

void BlaclJackWidget::addPlayer(QSharedPointer<Player> player)
{
    playersIcons->addPlayer(player);
}

void BlaclJackWidget::openGame(QList<QSharedPointer<Player>> playes)
{
    addPlayer(P_Authorization::getPlayer());

    for(QSharedPointer<Player> player : playes)
        addPlayer(player);

    show();
}
