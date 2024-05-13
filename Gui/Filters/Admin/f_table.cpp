#include "f_table.h"
#include "ui_f_table.h"

F_Table::F_Table(QWidget *parent) :
    BaseClasFilter(parent),
    ui(new Ui::F_Table)
{
    ui->setupUi(this);
    setButton(ui->applyFilter, ui->reset);
    startSetting();
}

F_Table::~F_Table()
{
    delete ui;
}

void F_Table::initFunSetFilters()
{
    functionsSetFilters =
    {
        {ui->start0end100,   [&]() {return " and MinBet >= '0' and MinBet <= '100'";}},
        {ui->start100end200,   [&]() {return " and MinBet >= '100' and MinBet <= '200'";}},
        {ui->start200end300,   [&]() {return " and MinBet >= '200' and MinBet <= '300'";}},
        {ui->yourStartAndEnd,   [&]() {return " and MinBet >= '" + ui->startMinBet->text() + "' and MinBet <= '" + ui->endMinBet->text() + "'";}},
        {ui->nameBlackJack, [&]() {return " and NameGame = 'BlackJack'";}},
        {ui->nameDevytka,   [&]() {return " and NameGame = 'Девятка'";}},
        {ui->allNameGame,   [&]() {return "";}}
    };
}

void F_Table::initFunVisibletFilters()
{
    functionsVisibleFilters =
    {
        {ui->nameGame, [&]() {ui->categoryNameGame->setVisible(!ui->categoryNameGame->isVisible());}},
        {ui->minBet, [&]() {ui->categoryMinBet->setVisible(!ui->categoryMinBet->isVisible());}}
    };
}

void F_Table::hideCategory()
{
    ui->categoryNameGame->hide();
    ui->categoryMinBet->hide();
}

void F_Table::customizationLiteEdit()
{
    ui->startMinBet->setValidator(new QIntValidator(this));
    ui->endMinBet->setValidator(new QIntValidator(this));
}
