#include "f_profit.h"
#include "ui_f_profit.h"

F_Profit::F_Profit(QWidget *parent) :
    BaseClasFilter(parent),
    ui(new Ui::F_Profit)
{
    ui->setupUi(this);
    setButton(ui->applyFilter, ui->reset);
    startSetting();
}

F_Profit::~F_Profit()
{
    delete ui;
}

void F_Profit::initFunSetFilters()
{

}

void F_Profit::initFunVisibletFilters()
{

}

void F_Profit::hideCategory()
{

}

void F_Profit::customizationLiteEdit()
{

}
