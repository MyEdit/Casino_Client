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
        {ui->minBetStart0end100,        [&]() {return "[Минимальная ставка] >= '0' and [Минимальная ставка] <= '100'";}},
        {ui->minBetStart100end200,      [&]() {return "[Минимальная ставка] >= '100' and [Минимальная ставка] <= '200'";}},
        {ui->minBetStart200end300,      [&]() {return "[Минимальная ставка] >= '200' and [Минимальная ставка] <= '300'";}},
        {ui->yourLimitsMinBet,          [&]() {return "[Минимальная ставка] >= '" + ui->minBetStart->text() + "' and [Минимальная ставка] <= '" + ui->minBetEnd->text() + "'";}},
        {ui->quantity2,                 [&]() {return "[Максимум игроков] = '2'";}},
        {ui->quantity3,                 [&]() {return "[Максимум игроков] = '3'";}},
        {ui->quantity4,                 [&]() {return "[Максимум игроков] = '4'";}},
        {ui->quantity5,                 [&]() {return "[Максимум игроков] = '5'";}},
        {ui->quantity6,                 [&]() {return "[Максимум игроков] = '6'";}},
        {ui->quantity7,                 [&]() {return "[Максимум игроков] = '7'";}},
        {ui->yourLimitsMaxPlayers,      [&]() {return "[Максимум игроков] >= '" + ui->maxPlayersStart->text() + "' and [Максимум игроков] <= '" + ui->maxPlayersEnd->text() + "'";}},
        {ui->minBalanceStart0end100,    [&]() {return "[Минимальный баланс] >= '0' and [Минимальный баланс] <= '100'";}},
        {ui->minBalanceStart100end200,  [&]() {return "[Минимальный баланс] >= '100' and [Минимальный баланс] <= '200'";}},
        {ui->minBalanceStart200end300,  [&]() {return "[Минимальный баланс] >= '200' and [Минимальный баланс] <= '300'";}},
        {ui->yourLimitsMinBalance,      [&]() {return "[Минимальный баланс] >= '" + ui->minBalanceStart->text() + "' and [Минимальный баланс] <= '" + ui->minBalanceEnd->text() + "'";}},
        {ui->nameBlackJack,             [&]() {return "[Игра] = 'BlackJack'";}},
        {ui->nameDevytka,               [&]() {return "[Игра] = 'Девятка'";}}
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
    connect(ui->yourLimitsMinBet, &QCheckBox::clicked, this, &F_Table::textChangeMinBet);

    connect(ui->maxPlayersStart, &QLineEdit::textChanged, this, &F_Table::textChangeMaxPlayers);
    connect(ui->maxPlayersEnd, &QLineEdit::textChanged, this, &F_Table::textChangeMaxPlayers);
    connect(ui->yourLimitsMaxPlayers, &QCheckBox::clicked, this, &F_Table::textChangeMaxPlayers);

    connect(ui->minBalanceStart, &QLineEdit::textChanged, this, &F_Table::textChangeMinBalance);
    connect(ui->minBalanceEnd, &QLineEdit::textChanged, this, &F_Table::textChangeMinBalance);
    connect(ui->yourLimitsMinBalance, &QCheckBox::clicked, this, &F_Table::textChangeMinBalance);
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
