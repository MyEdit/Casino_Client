#include "gametable.h"
#include "ui_gametable.h"

GameTable::GameTable(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameTable)
{
    ui->setupUi(this);
}

GameTable::~GameTable()
{
    delete ui;
}

void GameTable::updateTables()
{
    for(QSharedPointer<Table> table : Table::getTables())
    {
        Form* test = new Form(table);
        ui->verticalLayoutContent->addWidget(test);
    }
}
