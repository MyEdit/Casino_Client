#include "f_payment.h"
#include "ui_f_payment.h"

F_Payment::F_Payment(QWidget *parent) :
    BaseClasFilter(parent),
    ui(new Ui::F_Payment)
{
    ui->setupUi(this);
    setButton(ui->applyFilter, ui->reset);
    startSetting();
}

F_Payment::~F_Payment()
{
    delete ui;
}

void F_Payment::initFunSetFilters()
{

}

void F_Payment::initFunVisibletFilters()
{

}

void F_Payment::hideCategory()
{

}

void F_Payment::customizationLiteEdit()
{

}
