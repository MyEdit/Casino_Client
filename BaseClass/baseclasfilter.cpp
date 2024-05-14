#include "baseclasfilter.h"

BaseClasFilter::BaseClasFilter(QWidget *parent) : QDialog(parent)
{
}

void BaseClasFilter::reset()
{
    hideCategory();
    resetCategory(this);
}

void BaseClasFilter::setButton(QPushButton* applyFilterButton, QPushButton* resetButton)
{
    this->applyFilterButton = applyFilterButton;
    this->resetButton = resetButton;
}

void BaseClasFilter::setFilterWidgets()
{
    this->filterwidgets = findChildren<QWidget*>(QRegExp("category(\\w+)"));;
}

void BaseClasFilter::startSetting()
{
    connects();
    initFunSetFilters();
    initFunButton();
    visibleCategory();
    hideCategory();
    customizationLiteEdit();
    setFilterWidgets();
}

void BaseClasFilter::resetCategory(QWidget *parent)
{
    QList<QPushButton*> pushbuttons = parent->findChildren<QPushButton*>();
    for(QPushButton* pushbutton : pushbuttons)
        setBoldButtonCategoty(pushbutton, false);

    QList<QLineEdit*> lineEdits = parent->findChildren<QLineEdit*>();
    for(QLineEdit* lineEdit : lineEdits)
        lineEdit->clear();

    QList<QCheckBox*> checkBoxs = parent->findChildren<QCheckBox*>();
    for(QCheckBox* checkBox : checkBoxs)
        checkBox->setChecked(false);
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

    for(QWidget* widget : filterwidgets)
    {
        QStringList selectedFilters;

        QList<QCheckBox*> checkBoxs = widget->findChildren<QCheckBox*>();
        for(QCheckBox* checkBox : checkBoxs)
        {
            if(checkBox->isChecked())
                selectedFilters.append(functionsSetFilters[checkBox]());
        }

        if (!selectedFilters.isEmpty())
            filter += " and (" + selectedFilters.join(" OR ") + ")";
    }

    emit setFilter(filter);
    accept();
}

void BaseClasFilter::visibleCategory()
{
    QPushButton* selectButton = qobject_cast<QPushButton*>(sender());
    if (selectButton)
    {
        auto it = functionButton.find(selectButton);
        if (it != functionButton.end())
        {
            it.value()();

            if(!selectButton->objectName().contains("reset", Qt::CaseInsensitive))
                setBoldButtonCategoty(selectButton, !selectButton->font().bold());
        }
    }
}

void BaseClasFilter::setBoldButtonCategoty(QPushButton *button, const bool bold)
{
    QFont font = button->font();
    font.setBold(bold);
    button->setFont(font);
}

void BaseClasFilter::textChange(QCheckBox* checkBox, QLineEdit* lineEdit)
{
    checkBox->setChecked(true);

    if(lineEdit->text().isEmpty())
        lineEdit->setText("0");
}
