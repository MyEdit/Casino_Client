#include "allusers.h"
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
    connect(pagination, &Pagination::updateCurrentPageInLabel, this, &AllUsers::updateCurrentPageInLabel);
    connect(pagination, &Pagination::setMaxPageInLabel, this, &AllUsers::setValueToMaxPage);
}

void AllUsers::updateCurrentPageInLabel(int currentPage)
{
    ui->labelCurrentPage->setText(QString::number(currentPage));
}
