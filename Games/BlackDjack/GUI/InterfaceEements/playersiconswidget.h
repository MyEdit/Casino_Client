#ifndef PLAYERSICONSWIDGET_H
#define PLAYERSICONSWIDGET_H

#include <QWidget>

namespace Ui {
class PlayersIconsWidget;
}

class PlayersIconsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PlayersIconsWidget(QWidget *parent = nullptr);
    ~PlayersIconsWidget();

private:
    Ui::PlayersIconsWidget *ui;
};

#endif // PLAYERSICONSWIDGET_H
