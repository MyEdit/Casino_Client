#include "f_profit.h"
#include "ui_f_profit.h"

F_Profit::F_Profit(QWidget *parent) :
    BaseClasFilter(parent),
    ui(new Ui::F_Profit)
{
    ui->setupUi(this);
    setButton(ui->applyFilter, ui->reset);
    startSetting();
}

F_Profit::~F_Profit()
{
    delete ui;
}

void F_Profit::initFunSetFilters()
{
    functionsSetFilters =
    {
        {ui->oneDate,           [&]() {return "[Дата] = '" + ui->specificDate->date().toString("yyyy-MM-dd") + "'";}},
        {ui->yourLimitsDate,    [&]() {return "[Дата] BETWEEN '" + ui->dateStart->date().toString("yyyy-MM-dd") + "' AND '" + ui->dateEnd->date().toString("yyyy-MM-dd") + "'";}}
    };
}

void F_Profit::initFunButton()
{
    functionButton =
    {
        {ui->date,      [&]() {ui->categoryDate->setVisible(!ui->categoryDate->isVisible());}},
        {ui->resetDate, [&]() {resetCategory(ui->categoryDate);}}
    };
}

void F_Profit::hideCategory()
{
    ui->categoryDate->hide();
}

void F_Profit::customizationLiteEdit()
{

}

void F_Profit::connects()
{
    BaseClasFilter::connects();

    connect(ui->specificDate, &QDateEdit::dateChanged, this, &F_Profit::specificDateChanged);
    connect(ui->dateStart, &QDateEdit::dateChanged, this, &F_Profit::yourLimitsDateChanged);
    connect(ui->dateEnd, &QDateEdit::dateChanged, this, &F_Profit::yourLimitsDateChanged);
}

void F_Profit::specificDateChanged()
{
    ui->oneDate->setChecked(true);
}

void F_Profit::yourLimitsDateChanged()
{
    ui->yourLimitsDate->setChecked(true);
}
