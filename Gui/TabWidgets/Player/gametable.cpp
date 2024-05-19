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

void GameTable::stop()
{
    timer->stop();
}

void GameTable::start()
{
    timer->start(1000);
}

void GameTable::requestTables()
{
    timer = QSharedPointer<QTimer>(new QTimer(this));

    connect(timer.get(), &QTimer::timeout, this, [=]() {
        PacketTypes packettype = PacketTypes::P_SendTables;
        NetworkClient::sendToServer(&packettype, sizeof(PacketTypes));
    });

    start();
}

void GameTable::updateTables()
{
    QList<Form*> forms = this->findChildren<Form*>();

    deleteOldTable(forms);
    renderNewTable(forms);
}

void GameTable::deleteOldTable(QList<Form*>& forms)
{
    for (Form* form : forms)
    {
        bool found = false;
        for (const QSharedPointer<Table>& newTable : Table::getCopyListTabels())
        {
            if (form->getTable()->getSettings().ID == newTable->getSettings().ID)
            {
                form->update();
                found = true;
                break;
            }
        }
        if (!found)
        {
            delete form;
            forms.removeAll(form);
        }
    }
}

void GameTable::renderNewTable(QList<Form*>& forms)
{
    for (const QSharedPointer<Table>& newTable : Table::getCopyListTabels())
    {
        bool found = false;
        for (Form* form : forms)
        {
            if (form->getTable()->getSettings().ID == newTable->getSettings().ID)
            {
                found = true;
                break;
            }
        }
        if (!found)
            ui->verticalLayoutContent->addWidget(new Form(newTable));
    }
}
