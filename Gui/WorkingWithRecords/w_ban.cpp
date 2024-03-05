#include "w_ban.h"
#include "ui_w_ban.h"

Add_Ban::Add_Ban(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::W_Ban)
{
    ui->setupUi(this);
}

Add_Ban::~Add_Ban()
{
    delete ui;
}
