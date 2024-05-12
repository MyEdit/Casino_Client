#include "f_table.h"
#include "ui_f_table.h"

F_Table::F_Table(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::F_Table)
{
    ui->setupUi(this);
    connects();
    initFunSetFilters();
    initFunVisibletFilters();
    visibleCategory();
    startSetting();
}

F_Table::~F_Table()
{
    delete ui;
}

void F_Table::connects()
{
    connect(ui->applyFilter, &QPushButton::clicked, this, &F_Table::applyFilter);
    connect(ui->reset, &QPushButton::clicked, this, &F_Table::reset);

    QList<QPushButton*> pushbuttons = this->findChildren<QPushButton*>();
    for(QPushButton* pushbutton : pushbuttons)
    {
        if(pushbutton != ui->reset || pushbutton != ui->applyFilter)
            connect(ui->nameGame, &QPushButton::clicked, this, &F_Table::visibleCategory);
    }

}

void F_Table::applyFilter()
{
    QString filter;
    QList<QRadioButton*> radioButtons = this->findChildren<QRadioButton*>();
    for(QRadioButton* radioButton : radioButtons)
    {
        if(radioButton->isChecked())
            filter += functionsSetFilters[radioButton]();
    }

    emit setFilter(filter);
    accept();
}

void F_Table::initFunSetFilters()
{
    functionsSetFilters =
    {
        {ui->nameBlackJack, [&]() {return " and NameGame = 'BlackJack'";}},
        {ui->nameDevytka,   [&]() {return " and NameGame = 'Девятка'";}}
    };
}

void F_Table::initFunVisibletFilters()
{
    functionsVisibleFilters =
    {
        {ui->nameGame, [&]() {ui->categotyNameGame->setVisible(!ui->categotyNameGame->isVisible());}}
    };
}

void F_Table::visibleCategory()
{
    QPushButton* selectButton = qobject_cast<QPushButton*>(sender());
    if (selectButton)
    {
        auto it = functionsVisibleFilters.find(selectButton);
        if (it != functionsVisibleFilters.end())
        {
            it.value()();
            QFont font = selectButton->font();
            if (font.bold())
                font.setBold(false);
            else
                font.setBold(true);
            selectButton->setFont(font);
        }
    }
}

void F_Table::startSetting()
{
    ui->categotyNameGame->hide();
}

void F_Table::reset()
{
    close();
}
