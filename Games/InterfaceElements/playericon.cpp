#include "playericon.h"
#include "ui_playericon.h"

PlayerIcon::PlayerIcon(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlayerIcon)
{
    ui->setupUi(this);
    setVisible(false);
}

PlayerIcon::~PlayerIcon()
{
    delete ui;
}

void PlayerIcon::setPlayer(QSharedPointer<Player> player)
{
    this->player = player;
    setVisible(true);
    settingInformation();
}

void PlayerIcon::clearInfo()
{
    this->player = nullptr;
    ui->score->clear();
    setVisible(false);
}

void PlayerIcon::setScrore(int score)
{
    ui->score->setText(QString::number(score));
}

const QSharedPointer<Player> PlayerIcon::getPlayer()
{
    return player;
}

void PlayerIcon::settingInformation()
{
    ui->playerName->setText(player->getName());
    setImage();
}

void PlayerIcon::setImage()
{
    QSharedPointer<QPixmap> photo = BaseClassMainMenu::uploadingUserPhoto(player->getPhoto());

    ui->playerIcon->setScaledContents(true);

    if(photo)
        ui->playerIcon->setPixmap(*photo);
    else
        ui->playerIcon->hide();
}
