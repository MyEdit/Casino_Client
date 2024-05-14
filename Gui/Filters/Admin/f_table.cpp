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
        {ui->minBetStart0end100,        [&]() {return "MinBet >= '0' and MinBet <= '100'";}},
        {ui->minBetStart100end200,      [&]() {return "MinBet >= '100' and MinBet <= '200'";}},
        {ui->minBetStart200end300,      [&]() {return "MinBet >= '200' and MinBet <= '300'";}},
        {ui->yourLimitsMinBet,          [&]() {return "MinBet >= '" + ui->minBetStart->text() + "' and MinBet <= '" + ui->minBetEnd->text() + "'";}},
        {ui->quantity2,                 [&]() {return "MaxPlayers = '2'";}},
        {ui->quantity3,                 [&]() {return "MaxPlayers = '3'";}},
        {ui->quantity4,                 [&]() {return "MaxPlayers = '4'";}},
        {ui->quantity5,                 [&]() {return "MaxPlayers = '5'";}},
        {ui->quantity6,                 [&]() {return "MaxPlayers = '6'";}},
        {ui->quantity7,                 [&]() {return "MaxPlayers = '7'";}},
        {ui->yourLimitsMaxPlayers,      [&]() {return "MaxPlayers >= '" + ui->maxPlayersStart->text() + "' and MaxPlayers <= '" + ui->maxPlayersEnd->text() + "'";}},
        {ui->minBalanceStart0end100,    [&]() {return "MinBalance >= '0' and MinBalance <= '100'";}},
        {ui->minBalanceStart100end200,  [&]() {return "MinBalance >= '100' and MinBalance <= '200'";}},
        {ui->minBalanceStart200end300,  [&]() {return "MinBalance >= '200' and MinBalance <= '300'";}},
        {ui->yourLimitsMinBalance,      [&]() {return "MinBalance >= '" + ui->minBalanceStart->text() + "' and MinBalance <= '" + ui->minBalanceEnd->text() + "'";}},
        {ui->nameBlackJack,             [&]() {return "NameGame = 'BlackJack'";}},
        {ui->nameDevytka,               [&]() {return "NameGame = 'Девятка'";}}
    };
}

void F_Table::initFunButton()
{
    functionButton =
    {
        {ui->nameGame,          [&]() {ui->categoryNameGame->setVisible(!ui->categoryNameGame->isVisible());}},
        {ui->minBet,            [&]() {ui->categoryMinBet->setVisible(!ui->categoryMinBet->isVisible());}},
        {ui->maxPlayers,        [&]() {ui->categoryMaxPlayers->setVisible(!ui->categoryMaxPlayers->isVisible());}},
        {ui->minBalance,        [&]() {ui->categoryMinBalance->setVisible(!ui->categoryMinBalance->isVisible());}},
        {ui->resetMinBet,       [&]() {resetCategory(ui->categoryMinBet);}},
        {ui->resetMaxPlayers,   [&]() {resetCategory(ui->categoryMaxPlayers);}},
        {ui->resetNameGame,     [&]() {resetCategory(ui->categoryNameGame);}},
        {ui->resetMinBalance,   [&]() {resetCategory(ui->categoryMinBalance);}}
    };
}

void F_Table::hideCategory()
{
    ui->categoryNameGame->hide();
    ui->categoryMinBet->hide();
    ui->categoryMaxPlayers->hide();
    ui->categoryMinBalance->hide();
}

void F_Table::customizationLiteEdit()
{
    QIntValidator* intValidator = new QIntValidator(0, std::numeric_limits<int>::max(), this);

    ui->minBetStart->setValidator(intValidator);
    ui->minBetEnd->setValidator(intValidator);

    ui->maxPlayersStart->setValidator(intValidator);
    ui->maxPlayersEnd->setValidator(intValidator);

    ui->minBalanceStart->setValidator(intValidator);
    ui->minBalanceEnd->setValidator(intValidator);
}

void F_Table::connects()
{
    BaseClasFilter::connects();

    connect(ui->minBetStart, &QLineEdit::textChanged, this, &F_Table::textChangeMinBet);
    connect(ui->minBetEnd, &QLineEdit::textChanged, this, &F_Table::textChangeMinBet);

    connect(ui->maxPlayersStart, &QLineEdit::textChanged, this, &F_Table::textChangeMaxPlayers);
    connect(ui->maxPlayersEnd, &QLineEdit::textChanged, this, &F_Table::textChangeMaxPlayers);

    connect(ui->minBalanceStart, &QLineEdit::textChanged, this, &F_Table::textChangeMinBalance);
    connect(ui->minBalanceEnd, &QLineEdit::textChanged, this, &F_Table::textChangeMinBalance);
}

void F_Table::textChangeMinBet()
{
    textChange(ui->yourLimitsMinBet, ui->minBetStart);
}

void F_Table::textChangeMaxPlayers()
{
    textChange(ui->yourLimitsMaxPlayers, ui->maxPlayersStart);
}

void F_Table::textChangeMinBalance()
{
    textChange(ui->yourLimitsMinBalance, ui->minBalanceStart);
}
