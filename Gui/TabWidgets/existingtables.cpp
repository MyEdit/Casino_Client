#include "existingtables.h"
#include "ui_existingtables.h"

ExistingTables::ExistingTables(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExistingTables)
{
    ui->setupUi(this);

    assigningValues();
    creatingObjects();
    connects();
    workingWithTableView();
}

ExistingTables::~ExistingTables()
{
    delete ui;
}

void ExistingTables::workingWithTableView()
{
    workingIsTableView->settingVisualTableView();
}

void ExistingTables::setModel(ModelData model)
{
    pagination->acceptModel(model);
}

void ExistingTables::setValueToMaxPage(int maxPage)
{
    ui->labelMaxPage->setText(QString::number(maxPage));
}

void ExistingTables::assigningValues()
{
    boxsNameColumn.push_back(ui->searchColumn);
    boxsNameColumn.push_back(ui->sortingColumn);

    modelTypes = ModelTypes::ActiveTables;
}

void ExistingTables::creatingObjects()
{
    workingIsTableView = new WorkingIsTableView(ui->tableView, &boxsNameColumn);
    pagination = new Pagination(this, ui->tableView, ui->prevButton, ui->nextButton, workingIsTableView, modelTypes);
}

void ExistingTables::connects()
{
    connect(ui->prevButton, &QPushButton::clicked, pagination, &Pagination::prev);
    connect(ui->nextButton, &QPushButton::clicked, pagination, &Pagination::next);
    connect(pagination, &Pagination::updateCurrentPageInLabel, this, &ExistingTables::updateCurrentPageInLabel);
    connect(pagination, &Pagination::setMaxPageInLabel, this, &ExistingTables::setValueToMaxPage);
}

void ExistingTables::updateCurrentPageInLabel(int currentPage)
{
    ui->labelCurrentPage->setText(QString::number(currentPage));
}
