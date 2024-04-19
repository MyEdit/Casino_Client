#include "blacljackwidget.h"
#include "ui_blacljackwidget.h"

BlaclJackWidget::BlaclJackWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BlaclJackWidget)
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
