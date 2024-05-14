#include "f_user.h"
#include "ui_f_user.h"

F_User::F_User(QWidget *parent) :
    BaseClasFilter(parent),
    ui(new Ui::F_User)
{
    ui->setupUi(this);
    setButton(ui->applyFilter, ui->reset);
    startSetting();
}

F_User::~F_User()
{
    delete ui;
}

void F_User::initFunSetFilters()
{

}

void F_User::initFunButton()
{

}

void F_User::hideCategory()
{

}

void F_User::customizationLiteEdit()
{

}
