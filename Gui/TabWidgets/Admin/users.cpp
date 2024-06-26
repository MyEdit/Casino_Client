﻿#include "users.h"
#include "ui_users.h"

Users::Users(QWidget *parent) :
    BaseClassSearchWindow(parent),
    ui(new Ui::Users)
{
    ui->setupUi(this);

    baseSetting();
}

Users::~Users()
{
    delete ui;
}

void Users::setValueToMaxPage(const int maxPage)
{
    ui->labelMaxPage->setText(QString::number(maxPage));
}

void Users::assigningValues()
{
    BaseClassSearchWindow::assigningValues();

    boxsNameColumn.push_back(ui->searchColumn);
    boxsNameColumn.push_back(ui->sortingColumn);

    modelTypes = ModelTypes::Users;
}

void Users::creatingObjects()
{
    workingIsTableView = QSharedPointer<WorkingIsTableView>(new WorkingIsTableView(ui->tableView, &boxsNameColumn));
    pagination = QSharedPointer<Pagination>(new Pagination(this, ui->tableView, ui->searchColumn, workingIsTableView, modelTypes, ui->prevButton, ui->nextButton));
    filter = QSharedPointer<F_User>(new F_User());
}

void Users::connects()
{
    BaseClassSearchWindow::connects();

    connect(ui->prevButton, &QPushButton::clicked, pagination.get(), &Pagination::prev);
    connect(ui->nextButton, &QPushButton::clicked, pagination.get(), &Pagination::next);
    connect(ui->pushButton_search, &QPushButton::clicked, this, &Users::search);
    connect(ui->addUser, &QPushButton::clicked, this, &Users::openCreatRecotd);
    connect(ui->editUser, &QPushButton::clicked, this, &Users::openEditRecotd);
    connect(ui->deleteUser, &QPushButton::clicked, this, &Users::deleting);
    connect(ui->refreshData, &QPushButton::clicked, this, &Users::prepReloadModels);
    connect(ui->addBun, &QPushButton::clicked, this, &Users::openCreateBan);
    connect(ui->clearSearch, &QPushButton::clicked, this, &Users::clearSearchText);
    connect(ui->addFilter, &QPushButton::clicked, this, &Users::addFilter);
    connect(ui->clearFilter, &QPushButton::clicked, this, &Users::clearFilter);


    connect(ui->currentPage, &QLineEdit::textChanged, this, &Users::goToPage);
    connect(ui->searchText, &QLineEdit::textChanged, this, &Users::search);

    connect(ui->checkBox, &QCheckBox::stateChanged, this, &Users::selectTypeSearch);
    connect(ui->sorting, &QCheckBox::stateChanged, this, &Users::sorting);

    connect(ui->radioButton_Sorting, &QRadioButton::toggled, this, &Users::visibleSort);
    connect(ui->radioButton_Search, &QRadioButton::toggled, this, &Users::visibleSearch);
    connect(ui->radioButton_Editing, &QRadioButton::toggled, this, &Users::visibleEditing);
    connect(ui->radioButton_Filtr, &QRadioButton::toggled, this, &Users::visibleFiltr);

    connect(ui->sortingColumn, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &Users::sort);
    connect(ui->typeSorting, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &Users::sort);

    connect(ui->tableView->horizontalHeader(), &QHeaderView::sectionClicked, this, &Users::onHeaderClicked);
}

void Users::updateCurrentPageInLabel(const int currentPage)
{
    blockAndOperate(ui->currentPage, [&]() {ui->currentPage->setText(QString::number(currentPage));});
}

void Users::goToPage()
{
    if(ui->currentPage->text() == "0")
    {
        blockAndOperate(ui->currentPage, [&]() {ui->currentPage->clear();});
        return;
    }

    goToPageTimer.start(1000);
}

void Users::search()
{
    searchTimer.start(500);
}

void Users::onHeaderClicked(const int logicalIndex)
{
    if(!sortingOn)
        return;

    QString headerText = ui->tableView->model()->headerData(logicalIndex, Qt::Horizontal).toString();
    headerText = headerText.replace("\n", " ");

    if (ui->sortingColumn->currentText() == headerText)
    {
        int currentSortIndex = ui->typeSorting->currentIndex();
        currentSortIndex = (currentSortIndex + 1) % ui->typeSorting->count();
        ui->typeSorting->setCurrentIndex(currentSortIndex);
    }
    else
        settingValueInComboBox(ui->sortingColumn, headerText);

    if(ui->searchColumn->currentText() != headerText)
        settingValueInComboBox(ui->searchColumn, headerText);
}

void Users::prepReloadModels()
{
    if(sortingOn)
    {
        QString column = ui->sortingColumn->currentText();
        QString typeSort = typesSorting[ui->typeSorting->currentIndex()];
        pagination->setSort("ORDER BY [" + column + "] " + typeSort);
        ui->labelWhatKindSorting->setText(column + " по " + ui->typeSorting->currentText());
    }
    else
    {
        pagination->setSort("");
        ui->labelWhatKindSorting->setText("отсутствует");
    }

    ui->labelMaxPage->setText("????");
    blockAndOperate(ui->currentPage, [&]() {ui->currentPage->setText("0");});

    QString where = pagination->getWhere();
    if(defaultFilter == where || where.isEmpty())
        ui->labelWhatKindFilter->setText("отсутствует");
    else
        ui->labelWhatKindFilter->setText("установлен");

    pagination->reloadModels();
}

void Users::openCreatRecotd()
{
    workingWithUser = QSharedPointer<W_User>::create(QueryTypes::CreateEntry);
    workingWithUser->show();
}

void Users::openEditRecotd()
{
    int id = getValueFromSelectedRow(ui->tableView, 1).toInt();
    QString name = getValueFromSelectedRow(ui->tableView, 2).toString();
    QString passport = getValueFromSelectedRow(ui->tableView, 3).toString();
    QString balance = getValueFromSelectedRow(ui->tableView, 4).toString();
    QString logim = getValueFromSelectedRow(ui->tableView, 5).toString();
    QString password = getValueFromSelectedRow(ui->tableView, 6).toString();

    QSharedPointer<ObjectUser> user = QSharedPointer<ObjectUser>::create(id, name, passport, balance, logim, password);
    if (!user->inputDataIsValid())
        return;

    workingWithUser = QSharedPointer<W_User>::create(QueryTypes::UpdateEntry, user);
    workingWithUser->show();
}

void Users::openCreateBan()
{
    int id = getValueFromSelectedRow(ui->tableView, 1).toInt();
    QString name = getValueFromSelectedRow(ui->tableView, 2).toString();

    QSharedPointer<Ban> ban = QSharedPointer<Ban>::create(id, name);

    addBan = QSharedPointer<W_Ban>::create(QueryTypes::CreateEntry, ban);
    addBan->show();
}

void Users::deleting()
{
    QString table = "Users";
    QString idColumn = "ID_User";
    int id = getValueFromSelectedRow(ui->tableView, 1).toInt();

    deleteRecord(table, idColumn, id);
}

void Users::clearSearchText()
{
    ui->searchText->clear();
}

void Users::visibleSort(const bool flag)
{
    ui->label_3->setVisible(flag);
    ui->label_2->setVisible(flag);
    ui->sortingColumn->setVisible(flag);
    ui->typeSorting->setVisible(flag);
    ui->sorting->setVisible(flag);
}

void Users::visibleSearch(const bool flag)
{
    ui->label->setVisible(flag);
    ui->searchColumn->setVisible(flag);
    ui->searchText->setVisible(flag);
    ui->checkBox->setVisible(flag);
    ui->pushButton_search->setVisible(flag);
    ui->clearSearch->setVisible(flag);
}

void Users::visibleEditing(const bool flag)
{
    ui->addBun->setVisible(flag);
    ui->addUser->setVisible(flag);
    ui->editUser->setVisible(flag);
    ui->deleteUser->setVisible(flag);
}

void Users::visibleFiltr(const bool flag)
{
    ui->addFilter->setVisible(flag);
    ui->clearFilter->setVisible(flag);
}

void Users::addFilter()
{
    if (filter->exec() == QDialog::Accepted)
    {

    }
}

void Users::runSearch()
{
    pagination->search(ui->searchText->text(), typeSearch);
}

void Users::runGoToPage()
{
    pagination->goToPage(ui->currentPage->text());
}
