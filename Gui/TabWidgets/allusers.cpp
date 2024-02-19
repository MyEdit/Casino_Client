﻿#include "allusers.h"
#include "ui_allusers.h"

AllUsers::AllUsers(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AllUsers)
{
    ui->setupUi(this);

    assigningValues();
    creatingObjects();
    connects();
    workingWithTableView();

    pagination->start();
}

AllUsers::~AllUsers()
{
    delete ui;
}

void AllUsers::workingWithTableView()
{
    workingIsTableView->settingVisualTableView();
}

void AllUsers::setModel(ModelData model)
{
    pagination->acceptModel(model);
}

void AllUsers::setValueToMaxPage(int maxPage)
{
    ui->labelMaxPage->setText(QString::number(maxPage));
}

void AllUsers::assigningValues()
{
    boxsNameColumn.push_back(ui->searchColumn);
    boxsNameColumn.push_back(ui->sortingColumn);

    modelTypes = ModelTypes::Users;

    typeSearch = '%';

    goToPageTimer.setSingleShot(true);
    searchTimer.setSingleShot(true);
}

void AllUsers::creatingObjects()
{
    workingIsTableView = new WorkingIsTableView(ui->tableView, &boxsNameColumn);
    pagination = new Pagination(this, ui->tableView, ui->prevButton, ui->nextButton, workingIsTableView, modelTypes);
}

void AllUsers::connects()
{
    connect(ui->prevButton, &QPushButton::clicked, pagination, &Pagination::prev);
    connect(ui->nextButton, &QPushButton::clicked, pagination, &Pagination::next);
    connect(ui->pageNumberToNavigate, &QLineEdit::textChanged, this, &AllUsers::goToPage);
    connect(ui->searchText, &QLineEdit::textChanged, this, &AllUsers::search);
    connect(ui->checkBox, &QCheckBox::stateChanged, this, &AllUsers::selectTypeSearch);

    connect(pagination, &Pagination::updateCurrentPageInLabel, this, &AllUsers::updateCurrentPageInLabel);
    connect(pagination, &Pagination::setMaxPageInLabel, this, &AllUsers::setValueToMaxPage);
    connect(pagination, &Pagination::blockInterface, this, &AllUsers::blockingInterface);

    connect(workingIsTableView, &WorkingIsTableView::unlockInterface, this, &AllUsers::blockingInterface);

    connect(&goToPageTimer, &QTimer::timeout, this, [=]()
    {
        pagination->goToPage(ui->pageNumberToNavigate->text());
    });

    connect(&searchTimer, &QTimer::timeout, this, [=]()
    {
        pagination->search(ui->searchText->text(), typeSearch, ui->searchColumn);
    });
}

void AllUsers::updateCurrentPageInLabel(int currentPage)
{
    ui->labelCurrentPage->setText(QString::number(currentPage));
}

void AllUsers::blockAndOperate(QObject* widget, const std::function<void()>& operation)
{
    widget->blockSignals(true);
    operation();
    widget->blockSignals(false);
}

void AllUsers::goToPage()
{
    if(ui->pageNumberToNavigate->text() == "0")
    {
        blockAndOperate(ui->pageNumberToNavigate, [&]() {ui->pageNumberToNavigate->clear();});
        return;
    }

    goToPageTimer.start(1000);
}

void AllUsers::blockingInterface(bool flag)
{
    QList<QPushButton*> pushbuttons = this->findChildren<QPushButton*>();
    for(QPushButton* pushbutton : pushbuttons)
        pushbutton->setEnabled(flag);

    QList<QComboBox*> comboBoxs = this->findChildren<QComboBox*>();
    for(QComboBox* comboBox : comboBoxs)
        comboBox->setEnabled(flag);

    ui->sorting->setEnabled(flag);
    ui->pageNumberToNavigate->setEnabled(flag);
    ui->searchText->setEnabled(flag);
}

void AllUsers::search()
{
    searchTimer.start(1000);
}

void AllUsers::selectTypeSearch(int arg)
{
    if(arg == 2)
        typeSearch.clear();
    else if(arg == 0)
        typeSearch = '%';

    search();
}
