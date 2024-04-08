#include "playericon.h"
#include "ui_playericon.h"

PlayerIcon::PlayerIcon(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlayerIcon)
{
    ui->setupUi(this);
}

PlayerIcon::~PlayerIcon()
{
    delete ui;
}

void PlayerIcon::setPlayer(QSharedPointer<Player> player)
{
    this->player = player;
    settingInformation();
}

void PlayerIcon::settingInformation()
{
    ui->playerName->setText(player->getName());
    setImage();
}

void PlayerIcon::setImage()
{
    QPixmap photo;
    photo.loadFromData(player->getPhoto());

    QPixmap roundedPhoto(photo.size());
    roundedPhoto.fill(Qt::transparent);
    QPainterPath path;
    path.addRoundedRect(0, 0, photo.width(), photo.height(), photo.width() / 2, photo.height() / 2);

    QPainter painter(&roundedPhoto);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setClipPath(path);
    painter.drawPixmap(0, 0, photo);

    ui->playerIcon->setPixmap(roundedPhoto);
}
