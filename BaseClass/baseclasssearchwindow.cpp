#include "baseclasssearchwindow.h"
#include "Utils/pagination.h" //если перенести в заголовочный то возникают ошибки

BaseClassSearchWindow::BaseClassSearchWindow(QWidget *parent) :
    QWidget(parent)
{

}

void BaseClassSearchWindow::workingWithTableView()
{
    workingIsTableView->settingVisualTableView();
}

void BaseClassSearchWindow::blockAndOperate(QObject* widget, const std::function<void()>& operation)
{
    widget->blockSignals(true);
    operation();
    widget->blockSignals(false);
}

void BaseClassSearchWindow::blockingInterface(bool flag)
{
    QList<QPushButton*> pushbuttons = this->findChildren<QPushButton*>();
    for(QPushButton* pushbutton : pushbuttons)
        pushbutton->setEnabled(flag);

    QList<QComboBox*> comboBoxs = this->findChildren<QComboBox*>();
    for(QComboBox* comboBox : comboBoxs)
        comboBox->setEnabled(flag);

    QList<QCheckBox*> checkBoxs = this->findChildren<QCheckBox*>();
    for(QCheckBox* checkBox : checkBoxs)
        checkBox->setEnabled(flag);

    QList<QLineEdit*> lineEdits = this->findChildren<QLineEdit*>();
    for(QLineEdit* lineEdit : lineEdits)
        lineEdit->setEnabled(flag);
}


void BaseClassSearchWindow::settingValueInComboBox(QComboBox* comboBox, QString& headerText)
{
    int comboBoxIndex = comboBox->findText(headerText);
    if (comboBoxIndex != -1)
        comboBox->setCurrentIndex(comboBoxIndex);
}

void BaseClassSearchWindow::setModel(ModelData model)
{
    pagination->acceptModel(model);
}

void BaseClassSearchWindow::sorting(int arg)
{
    sortingOn = (arg == 2) ? true : false;
    prepReloadModels();
}

void BaseClassSearchWindow::selectTypeSearch(int arg)
{
    if(arg == 2)
        typeSearch.clear();
    else if(arg == 0)
        typeSearch = '%';

    search();
}

void BaseClassSearchWindow::baseSetting()
{
    assigningValues();
    creatingObjects();
    connects();
    workingWithTableView();

    pagination->start();
}

void BaseClassSearchWindow::sort()
{
    if(sortingOn)
        prepReloadModels();
}

QVariant BaseClassSearchWindow::getValueFromSelectedRow(QTableView* tableView, int collumn)
{
    QModelIndex currentDiscount = tableView->currentIndex();
    return tableView->model()->data(tableView->model()->index(currentDiscount.row(), collumn), 0);
}
