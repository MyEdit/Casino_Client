#include "f_payment.h"
#include "ui_f_payment.h"

F_Payment::F_Payment(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::F_Payment)
{
    ui->setupUi(this);
}

F_Payment::~F_Payment()
{
    delete ui;
}
