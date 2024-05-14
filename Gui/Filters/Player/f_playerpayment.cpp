#include "f_playerpayment.h"
#include "ui_f_playerpayment.h"

F_PlayerPayment::F_PlayerPayment(QWidget *parent) :
    BaseClasFilter(parent),
    ui(new Ui::F_PlayerPayment)
{
    ui->setupUi(this);
    setButton(ui->applyFilter, ui->reset);
    startSetting();
}

F_PlayerPayment::~F_PlayerPayment()
{
    delete ui;
}

void F_PlayerPayment::initFunSetFilters()
{

}

void F_PlayerPayment::initFunButton()
{

}

void F_PlayerPayment::hideCategory()
{

}

void F_PlayerPayment::customizationLiteEdit()
{

}
