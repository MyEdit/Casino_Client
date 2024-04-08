#include "playersiconswidget.h"
#include "ui_playersiconswidget.h"

PlayersIconsWidget::PlayersIconsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlayersIconsWidget)
{
    ui->setupUi(this);
    assigningValues();
    rendering();
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
}

void PlayersIconsWidget::rendering()
{
    ui->layoutIcon_1->addWidget(playerIcons[0].get());
    ui->layoutIcon_2->addWidget(playerIcons[1].get());
    ui->layoutIcon_3->addWidget(playerIcons[2].get());
    ui->layoutIcon_4->addWidget(playerIcons[3].get());
    ui->layoutIcon_5->addWidget(playerIcons[4].get());
    ui->layoutIcon_6->addWidget(playerIcons[5].get());
    ui->layoutIcon_7->addWidget(playerIcons[6].get());
}
