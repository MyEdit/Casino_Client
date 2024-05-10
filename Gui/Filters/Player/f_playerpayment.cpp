#include "f_playerpayment.h"
#include "ui_f_playerpayment.h"

F_PlayerPayment::F_PlayerPayment(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::F_PlayerPayment)
{
    ui->setupUi(this);
}

F_PlayerPayment::~F_PlayerPayment()
{
    delete ui;
}
