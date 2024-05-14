#include "playericon.h"
#include "ui_playericon.h"

PlayerIcon::PlayerIcon(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlayerIcon)
{
    ui->setupUi(this);
    setVisible(false);

    ui->score->clear();
    ui->labelScore->setVisible(false);
    ui->score->setVisible(false);
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
    ui->labelScore->setVisible(false);
    ui->score->setVisible(false);

    ui->countCard->setText("0");

    setVisible(false);
}

void PlayerIcon::setScrore(int score)
{
    ui->labelScore->setVisible(true);
    ui->score->setVisible(true);
    ui->score->setText(QString::number(score));
}

void PlayerIcon::takenCard()
{
    ui->countCard->setText(QString::number(++countCard));
}

void PlayerIcon::resetCountCard()
{
    countCard = 0;
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
