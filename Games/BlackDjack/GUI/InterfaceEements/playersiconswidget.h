#ifndef PLAYERSICONSWIDGET_H
#define PLAYERSICONSWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include "Games/BlackDjack/GUI/InterfaceEements/playericon.h"
#include "Network/PacketsActions/p_authorization.h"

class PlayerIcon;

namespace Ui {
class PlayersIconsWidget;
}

class PlayersIconsWidget : public QWidget
{
    Q_OBJECT
    Ui::PlayersIconsWidget *ui;
    QList<QSharedPointer<PlayerIcon>> playerIcons;
    QMap<QSharedPointer<PlayerIcon>, QVBoxLayout*> widgetLayer;

public:
    explicit PlayersIconsWidget(QWidget *parent = nullptr);
    ~PlayersIconsWidget();

    void addPlayer(QSharedPointer<Player> player);
    QList<QSharedPointer<PlayerIcon>> getPlayerIcons();
    const QRect getRectPlayerIcon(QSharedPointer<PlayerIcon> playerIcon);
    void fullClearInfo();

private:
    void rendering();
    void assigningValues();
};

#endif // PLAYERSICONSWIDGET_H
