#include "w_table.h"
#include "ui_w_table.h"

Add_Table::Add_Table(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::W_Table)
{
    ui->setupUi(this);
}

Add_Table::~Add_Table()
{
    delete ui;
}
