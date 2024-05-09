#include "f_stuffuser.h"
#include "ui_f_stuffuser.h"

F_StuffUser::F_StuffUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::F_StuffUser)
{
    ui->setupUi(this);
}

F_StuffUser::~F_StuffUser()
{
    delete ui;
}
