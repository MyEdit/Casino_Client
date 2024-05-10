#include "f_table.h"
#include "ui_f_table.h"

F_Table::F_Table(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::F_Table)
{
    ui->setupUi(this);
    connets();
}

F_Table::~F_Table()
{
    delete ui;
}

void F_Table::connets()
{
    connect(ui->applyFilter, &QPushButton::clicked, this, &F_Table::applyFilter);
    connect(ui->reset, &QPushButton::clicked, this, &F_Table::reset);
}

void F_Table::applyFilter()
{
    accept();
}

void F_Table::reset()
{
    close();
}
