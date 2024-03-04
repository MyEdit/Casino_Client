#include "add_stuffuser.h"
#include "ui_add_stuffuser.h"

Add_StuffUser::Add_StuffUser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Add_StuffUser)
{
    ui->setupUi(this);
}

Add_StuffUser::~Add_StuffUser()
{
    delete ui;
}
