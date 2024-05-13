#include "f_playercredit.h"
#include "ui_f_playercredit.h"

F_PlayerCredit::F_PlayerCredit(QWidget *parent) :
    BaseClasFilter(parent),
    ui(new Ui::F_PlayerCredit)
{
    ui->setupUi(this);
    setButton(ui->applyFilter, ui->reset);
    startSetting();
}

F_PlayerCredit::~F_PlayerCredit()
{
    delete ui;
}

void F_PlayerCredit::initFunSetFilters()
{

}

void F_PlayerCredit::initFunVisibletFilters()
{

}

void F_PlayerCredit::hideCategory()
{

}

void F_PlayerCredit::customizationLiteEdit()
{

}
