#include "creategametable.h"
#include "ui_creategametable.h"

CreateGameTable::CreateGameTable(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateGameTable)
{
    ui->setupUi(this);
    ui->tableHasBeenCreated->setVisible(false);
}

CreateGameTable::~CreateGameTable()
{
    delete ui;
}
