#include "f_credit.h"
#include "ui_f_credit.h"

F_Credit::F_Credit(QWidget *parent) :
    BaseClasFilter(parent),
    ui(new Ui::F_Credit)
{
    ui->setupUi(this);
    setButton(ui->applyFilter, ui->reset);
    startSetting();
}

F_Credit::~F_Credit()
{
    delete ui;
}

void F_Credit::initFunSetFilters()
{

}

void F_Credit::initFunButton()
{

}

void F_Credit::hideCategory()
{

}

void F_Credit::customizationLiteEdit()
{

}

