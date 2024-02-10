#include "allusers.h"
#include "ui_allusers.h"

AllUsers::AllUsers(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AllUsers)
{
    ui->setupUi(this);
}

AllUsers::~AllUsers()
{
    delete ui;
}

void AllUsers::setModel(QStandardItemModel* model)
{
    ui->tableView->setModel(model);
}
