#include "f_stuffuser.h"
#include "ui_f_stuffuser.h"

F_StuffUser::F_StuffUser(QWidget *parent) :
    BaseClasFilter(parent),
    ui(new Ui::F_StuffUser)
{
    ui->setupUi(this);
    setButton(ui->applyFilter, ui->reset);
    startSetting();
}

F_StuffUser::~F_StuffUser()
{
    delete ui;
}

void F_StuffUser::initFunSetFilters()
{

}

void F_StuffUser::initFunButton()
{

}

void F_StuffUser::hideCategory()
{

}

void F_StuffUser::customizationLiteEdit()
{

}
