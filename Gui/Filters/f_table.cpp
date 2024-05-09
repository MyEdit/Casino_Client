#include "f_table.h"
#include "ui_f_table.h"

F_Table::F_Table(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::F_Table)
{
    ui->setupUi(this);
}

F_Table::~F_Table()
{
    delete ui;
}
