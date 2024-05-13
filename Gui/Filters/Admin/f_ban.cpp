#include "f_ban.h"
#include "ui_f_ban.h"

F_Ban::F_Ban(QWidget *parent) :
    BaseClasFilter(parent),
    ui(new Ui::F_Ban)
{
    ui->setupUi(this);
    setButton(ui->applyFilter, ui->reset);
    startSetting();
}

F_Ban::~F_Ban()
{
    delete ui;
}

void F_Ban::initFunSetFilters()
{

}

void F_Ban::initFunVisibletFilters()
{

}

void F_Ban::hideCategory()
{

}

void F_Ban::customizationLiteEdit()
{

}
