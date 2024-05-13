#include "baseclasfilter.h"

BaseClasFilter::BaseClasFilter(QWidget *parent) : QDialog(parent)
{
}

void BaseClasFilter::reset()
{
    hideCategory();

    QList<QPushButton*> pushbuttons = this->findChildren<QPushButton*>();
    for(QPushButton* pushbutton : pushbuttons)
        setBoldButtonCategoty(pushbutton, false);

    QList<QLineEdit*> lineEdits = this->findChildren<QLineEdit*>();
    for(QLineEdit* lineEdit : lineEdits)
        lineEdit->clear();

    QList<QRadioButton*> radioButtons = this->findChildren<QRadioButton*>();
    for(QRadioButton* radioButton : radioButtons)
    {
        radioButton->setAutoExclusive(false);
        radioButton->setChecked(false);
        radioButton->setAutoExclusive(true);
    }
}

void BaseClasFilter::setButton(QPushButton* applyFilterButton, QPushButton* resetButton)
{
    this->applyFilterButton = applyFilterButton;
    this->resetButton = resetButton;
}

void BaseClasFilter::startSetting()
{
    connects();
    initFunSetFilters();
    initFunVisibletFilters();
    visibleCategory();
    hideCategory();
    customizationLiteEdit();
}

void BaseClasFilter::connects()
{
    connect(applyFilterButton, &QPushButton::clicked, this, &BaseClasFilter::applyFilter);
    connect(resetButton, &QPushButton::clicked, this, &BaseClasFilter::reset);

    QList<QPushButton*> pushbuttons = this->findChildren<QPushButton*>();
    for(QPushButton* pushbutton : pushbuttons)
    {
        if(pushbutton != resetButton || pushbutton != applyFilterButton)
            connect(pushbutton, &QPushButton::clicked, this, &BaseClasFilter::visibleCategory);
    }
}

void BaseClasFilter::applyFilter()
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

void BaseClasFilter::visibleCategory()
{
    QPushButton* selectButton = qobject_cast<QPushButton*>(sender());
    if (selectButton)
    {
        auto it = functionsVisibleFilters.find(selectButton);
        if (it != functionsVisibleFilters.end())
        {
            it.value()();
            selectCategory(selectButton);
        }
    }
}

void BaseClasFilter::selectCategory(QPushButton *button)
{
    setBoldButtonCategoty(button, !button->font().bold());
}

void BaseClasFilter::setBoldButtonCategoty(QPushButton *button, const bool bold)
{
    QFont font = button->font();
    font.setBold(bold);
    button->setFont(font);
}
