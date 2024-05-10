#include "f_playercredit.h"
#include "ui_f_playercredit.h"

F_PlayerCredit::F_PlayerCredit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::F_PlayerCredit)
{
    ui->setupUi(this);
}

F_PlayerCredit::~F_PlayerCredit()
{
    delete ui;
}
