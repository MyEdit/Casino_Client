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
        {ui->allMinBet,             [&]() {return "";}},
        {ui->start0end100,          [&]() {return " and MinBet >= '0' and MinBet <= '100'";}},
        {ui->start100end200,        [&]() {return " and MinBet >= '100' and MinBet <= '200'";}},
        {ui->start200end300,        [&]() {return " and MinBet >= '200' and MinBet <= '300'";}},
        {ui->yourLimitsMinBet,      [&]() {return " and MinBet >= '" + ui->startMinBet->text() + "' and MinBet <= '" + ui->endMinBet->text() + "'";}},
        {ui->allMaxPlayers,         [&]() {return "";}},
        {ui->specQuantityMaxPlayrs, [&]() {return " and MaxPlayers = '" + ui->quantityMaxPlayrs->currentText() + "'";}},
        {ui->yourLimitsMaxPlayers,  [&]() {return " and MaxPlayers >= '" + ui->startMaxPlayers->text() + "' and MaxPlayers <= '" + ui->endMaxPlayers->text() + "'";}},
        {ui->allNameGame,           [&]() {return "";}},
        {ui->nameBlackJack,         [&]() {return " and NameGame = 'BlackJack'";}},
        {ui->nameDevytka,           [&]() {return " and NameGame = 'Девятка'";}}
    };
}

void F_Table::initFunVisibletFilters()
{
    functionsVisibleFilters =
    {
        {ui->nameGame, [&]() {ui->categoryNameGame->setVisible(!ui->categoryNameGame->isVisible());}},
        {ui->minBet, [&]() {ui->categoryMinBet->setVisible(!ui->categoryMinBet->isVisible());}},
        {ui->maxPlayers, [&]() {ui->categoryMaxPlayers->setVisible(!ui->categoryMaxPlayers->isVisible());}},
    };
}

void F_Table::hideCategory()
{
    ui->categoryNameGame->hide();
    ui->categoryMinBet->hide();
    ui->categoryMaxPlayers->hide();
}

void F_Table::customizationLiteEdit()
{
    QIntValidator* intValidator = new QIntValidator(0, std::numeric_limits<int>::max(), this);

    ui->startMinBet->setValidator(intValidator);
    ui->endMinBet->setValidator(intValidator);
    ui->startMaxPlayers->setValidator(intValidator);
    ui->endMaxPlayers->setValidator(intValidator);
}

void F_Table::connects()
{
    BaseClasFilter::connects();

    connect(ui->startMinBet, &QLineEdit::textChanged, this, &F_Table::textChangeMinBet);
    connect(ui->endMinBet, &QLineEdit::textChanged, this, &F_Table::textChangeMinBet);

    connect(ui->startMaxPlayers, &QLineEdit::textChanged, this, &F_Table::textChangeMaxPlayers);
    connect(ui->endMaxPlayers, &QLineEdit::textChanged, this, &F_Table::textChangeMaxPlayers);
    connect(ui->quantityMaxPlayrs, QOverload<int>::of(&QComboBox::activated), this, &F_Table::currentTextMaxPlayrs);
}

void F_Table::textChangeMinBet()
{
    ui->yourLimitsMinBet->setChecked(true);

    if(ui->startMinBet->text().isEmpty())
        ui->startMinBet->setText("0");
}

void F_Table::textChangeMaxPlayers()
{
    ui->yourLimitsMaxPlayers->setChecked(true);

    if(ui->startMaxPlayers->text().isEmpty())
        ui->startMaxPlayers->setText("0");
}

void F_Table::currentTextMaxPlayrs()
{
    ui->specQuantityMaxPlayrs->setChecked(true);
}
