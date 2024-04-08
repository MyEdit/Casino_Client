#ifndef PLAYERSICONSWIDGET_H
#define PLAYERSICONSWIDGET_H

#include <QWidget>
#include "Games/BlackDjack/GUI/InterfaceEements/playericon.h"

namespace Ui {
class PlayersIconsWidget;
}

class PlayersIconsWidget : public QWidget
{
    Q_OBJECT
    Ui::PlayersIconsWidget *ui;
    QList<QSharedPointer<PlayerIcon>> playerIcons;

public:
    explicit PlayersIconsWidget(QWidget *parent = nullptr);
    ~PlayersIconsWidget();

private:
    void rendering();
    void assigningValues();
};

#endif // PLAYERSICONSWIDGET_H
