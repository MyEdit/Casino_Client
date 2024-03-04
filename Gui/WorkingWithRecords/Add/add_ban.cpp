#include "add_ban.h"
#include "ui_add_ban.h"

Add_Ban::Add_Ban(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Add_Ban)
{
    ui->setupUi(this);
}

Add_Ban::~Add_Ban()
{
    delete ui;
}
