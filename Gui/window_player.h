#ifndef WINDOW_PLAYER_H
#define WINDOW_PLAYER_H

#include <QMainWindow>

namespace Ui {
class Window_Player;
}

class Window_Player : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window_Player(QWidget *parent = nullptr);
    ~Window_Player();

private:
    Ui::Window_Player *ui;
};

#endif // WINDOW_PLAYER_H
