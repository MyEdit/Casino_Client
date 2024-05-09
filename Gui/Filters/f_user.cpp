#include "f_user.h"
#include "ui_f_user.h"

F_User::F_User(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::F_User)
{
    ui->setupUi(this);
}

F_User::~F_User()
{
    delete ui;
}
