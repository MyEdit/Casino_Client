#include "add_table.h"
#include "ui_add_table.h"

Add_Table::Add_Table(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Add_Table)
{
    ui->setupUi(this);
}

Add_Table::~Add_Table()
{
    delete ui;
}
