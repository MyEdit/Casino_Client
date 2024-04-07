#ifndef BLACLJACKWIDGET_H
#define BLACLJACKWIDGET_H

#include <QWidget>
#include <QTimer>
#include "Games/BlackDjack/GUI/InterfaceEements/blackjecktablewidget.h"
#include "Games/BlackDjack/GUI/InterfaceEements/playersiconswidget.h"

namespace Ui {
class BlaclJackWidget;
}

class BlaclJackWidget : public QWidget
{
    Q_OBJECT
    Ui::BlaclJackWidget *ui;
    QSharedPointer<BlackJeckTableWidget> tabel;
    QSharedPointer<PlayersIconsWidget> playersIcons;

public:
    explicit BlaclJackWidget(QWidget *parent = nullptr);
    ~BlaclJackWidget();

private:
    void rendering();
    void renderingTable();
    void renderingPlayersIcons();
    void resizeEvent(QResizeEvent *event) override;
};

#endif // BLACLJACKWIDGET_H
