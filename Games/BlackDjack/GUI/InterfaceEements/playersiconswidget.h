#ifndef PLAYERSICONSWIDGET_H
#define PLAYERSICONSWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include "Games/BlackDjack/GUI/InterfaceEements/playericon.h"
#include "Network/PacketsActions/p_authorization.h"

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
    QRect getRectPlayerIcon(QSharedPointer<PlayerIcon> playerIcon);

private:
    void rendering();
    void assigningValues();
    void connects();
    void takeCard();
    void doNotTakeCard();
    void blocingInterface(bool flag);
};

#endif // PLAYERSICONSWIDGET_H
