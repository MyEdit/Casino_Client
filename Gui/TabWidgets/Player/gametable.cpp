#include "gametable.h"
#include "ui_gametable.h"

GameTable::GameTable(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameTable)
{
    ui->setupUi(this);
    requestTables();
}

GameTable::~GameTable()
{
    delete ui;
}

void GameTable::updateTables()
{
    QLayoutItem* item;
    while ((item = ui->verticalLayoutContent->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }

    for(QSharedPointer<Table> table : Table::tables)
    {
        Form* formTable = new Form(table);
        ui->verticalLayoutContent->addWidget(formTable);
    }
}

void GameTable::requestTables()
{
    QTimer* timer = new QTimer(this);

    connect(timer, &QTimer::timeout, this, [=]() {
        PacketTypes packettype = PacketTypes::P_SendTables;
        NetworkClient::sendToServer(&packettype, sizeof(PacketTypes));
    });

    timer->start(1000);
}
