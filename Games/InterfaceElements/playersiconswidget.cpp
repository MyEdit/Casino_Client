#include "playersiconswidget.h"
#include "ui_playersiconswidget.h"

PlayersIconsWidget::PlayersIconsWidget(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::PlayersIconsWidget)
{
    ui->setupUi(this);
    assigningValues();
    rendering();
}

void PlayersIconsWidget::assigningValues()
{
    for(int i = 0; i < maxPlayers; i++)
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

const QRect PlayersIconsWidget::getRectPlayerIcon(QSharedPointer<PlayerIcon> playerIcon)
{
    return widgetLayer[playerIcon]->geometry();
}

void PlayersIconsWidget::addPlayer(QSharedPointer<Player> player)
{
    for(QSharedPointer<PlayerIcon> playersIcon : playerIcons)
    {
        if(playersIcon->getPlayer() == nullptr)
        {
            playersIcon->setPlayer(player);
            break;
        }
    }
}

void PlayersIconsWidget::fullClearInfo()
{
    for(QSharedPointer<PlayerIcon> playersIcon : getPlayerIcons())
        playersIcon->clearInfo();
}

void PlayersIconsWidget::setMyScore(int score)
{
    for(QSharedPointer<PlayerIcon> playersIcon : getPlayerIcons())
    {
        if(playersIcon->getPlayer() == P_Authorization::getPlayer())
        {
            playersIcon->setScrore(score);
            break;
        }
    }
}

void PlayersIconsWidget::takenCard(const QString &nickname)
{
    for(QSharedPointer<PlayerIcon> playersIcon : getPlayerIcons())
    {
        if(playersIcon->getPlayer()->getLogin() == nickname)
            playersIcon->takenCard();
    }
}

void PlayersIconsWidget::resetCountCard()
{
    for(QSharedPointer<PlayerIcon> playersIcon : getPlayerIcons())
        playersIcon->resetCountCard();
}
