#include "window_auth.h"
#include "ui_window_auth.h"

Window_Auth::Window_Auth(QWidget *parent) : QMainWindow(parent), ui(new Ui::Window_Auth)
{
    ui->setupUi(this);
}

Window_Auth::~Window_Auth()
{
    delete ui;
}

void Window_Auth::on_Button_Auth_clicked()
{
    P_Authorization::sendData(ui->textBox_Login->text(), ui->textBox_Password->text());
}
