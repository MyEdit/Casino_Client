#include "window_auth.h"
#include "ui_window_auth.h"
#include <networkclient.h>

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
    QString login = ui->textBox_Login->text();
    QString password = ui->textBox_Password->text();

    PacketTypes packettype = P_Authorization;
    NetworkClient::sendToServer((char*)&packettype, sizeof(PacketTypes));
    NetworkClient::sendToServer((char*)login.toUtf8().constData());
    NetworkClient::sendToServer((char*)password.toUtf8().constData());
}
