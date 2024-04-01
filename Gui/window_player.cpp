#include "window_player.h"
#include "ui_window_player.h"

Window_Player::Window_Player(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window_Player)
{
    ui->setupUi(this);
}

Window_Player::~Window_Player()
{
    delete ui;
}
