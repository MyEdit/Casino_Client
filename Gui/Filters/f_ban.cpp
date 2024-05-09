#include "f_ban.h"
#include "ui_f_ban.h"

F_Ban::F_Ban(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::F_Ban)
{
    ui->setupUi(this);
}

F_Ban::~F_Ban()
{
    delete ui;
}
