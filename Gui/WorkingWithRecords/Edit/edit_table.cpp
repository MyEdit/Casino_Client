#include "edit_table.h"
#include "ui_edit_table.h"

Edit_Table::Edit_Table(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Edit_Table)
{
    ui->setupUi(this);
}

Edit_Table::~Edit_Table()
{
    delete ui;
}
