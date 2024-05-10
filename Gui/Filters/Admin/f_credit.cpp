#include "f_credit.h"
#include "ui_f_credit.h"

F_Credit::F_Credit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::F_Credit)
{
    ui->setupUi(this);
}

F_Credit::~F_Credit()
{
    delete ui;
}
