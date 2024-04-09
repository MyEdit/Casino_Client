#include "playersiconswidget.h"
#include "ui_playersiconswidget.h"

PlayersIconsWidget::PlayersIconsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlayersIconsWidget)
{
    ui->setupUi(this);
    assigningValues();
    rendering();
    connects();
}

PlayersIconsWidget::~PlayersIconsWidget()
{
    delete ui;
}

void PlayersIconsWidget::assigningValues()
{
    for(int i = 0; i < 7; i++)
    {
        QSharedPointer<PlayerIcon> plaerIcon = QSharedPointer<PlayerIcon>(new PlayerIcon());
        playerIcons.append(plaerIcon);
    }

    widgetLayer =
    {
        {playerIcons[0], ui->layoutIcon_1},
        {playerIcons[1], ui->layoutIcon_2},
        {playerIcons[2], ui->layoutIcon_3},
        {playerIcons[3], ui->layoutIcon_4},
        {playerIcons[4], ui->layoutIcon_5},
        {playerIcons[5], ui->layoutIcon_6},
        {playerIcons[6], ui->layoutIcon_7}
    };
}

void PlayersIconsWidget::rendering()
{
    QMap<QSharedPointer<PlayerIcon>, QVBoxLayout*>::iterator it;
    for (it = widgetLayer.begin(); it != widgetLayer.end(); it++)
        it.value()->addWidget(it.key().get());
}

QList<QSharedPointer<PlayerIcon>> PlayersIconsWidget::getPlayerIcons()
{
    QList<QSharedPointer<PlayerIcon>> icon;

    for(QSharedPointer<PlayerIcon> playersIcon : playerIcons)
    {
        if(playersIcon->getPlayer() != nullptr)
            icon.append(playersIcon);
    }

    return icon;
}

void PlayersIconsWidget::connects()
{
    connect(ui->buttonTakeCard, &QPushButton::clicked, this, &PlayersIconsWidget::takeCard);
    connect(ui->buttonDoNotTakeCard, &QPushButton::clicked, this, &PlayersIconsWidget::doNotTakeCard);
}

void PlayersIconsWidget::takeCard()
{
    //TODO: послать запрос на взятие карты

    blocingInterface(false);
}

void PlayersIconsWidget::doNotTakeCard()
{
    //TODO: послать запрос на скип хода

    blocingInterface(false);
}

void PlayersIconsWidget::blocingInterface(bool flag)
{
    ui->buttonTakeCard->setEnabled(flag);
    ui->buttonDoNotTakeCard->setEnabled(flag);
}

QRect PlayersIconsWidget::getRectPlayerIcon(QSharedPointer<PlayerIcon> playerIcon)
{
    return widgetLayer[playerIcon]->geometry();
}
