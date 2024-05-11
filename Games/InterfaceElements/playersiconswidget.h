#ifndef PLAYERSICONSWIDGET_H
#define PLAYERSICONSWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include "Games/InterfaceElements/playericon.h"
#include "Users/player.h"

class PlayerIcon;
class Player;

namespace Ui {
class PlayersIconsWidget;
}

class PlayersIconsWidget : public QWidget
{
    Q_OBJECT
    Ui::PlayersIconsWidget *ui;
    QList<QSharedPointer<PlayerIcon>> playerIcons;
    QMap<QSharedPointer<PlayerIcon>, QVBoxLayout*> widgetLayer;
    const int maxPlayers {7};

public:
    explicit PlayersIconsWidget(QWidget* parent = nullptr);
    virtual ~PlayersIconsWidget() {}

    void addPlayer(QSharedPointer<Player> player);
    QList<QSharedPointer<PlayerIcon>> getPlayerIcons();
    const QRect getRectPlayerIcon(QSharedPointer<PlayerIcon> playerIcon);
    void fullClearInfo();
    void setMyScore(int score);

private:
    void rendering();
    void assigningValues();
};

#endif // PLAYERSICONSWIDGET_H
