#include "allusers.h"
#include "ui_allusers.h"

AllUsers::AllUsers(QWidget *parent) :
    BaseClassSearchWindow(parent),
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
    connect(ui->pushButton_search, &QPushButton::clicked, this, &AllUsers::search);

    connect(ui->pageNumberToNavigate, &QLineEdit::textChanged, this, &AllUsers::goToPage);
    connect(ui->searchText, &QLineEdit::textChanged, this, &AllUsers::search);

    connect(ui->checkBox, &QCheckBox::stateChanged, this, &AllUsers::selectTypeSearch);
    connect(ui->sorting, &QCheckBox::stateChanged, this, &AllUsers::sorting);

    connect(ui->sortingColumn, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &AllUsers::sort);
    connect(ui->typeSorting, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &AllUsers::sort);

    connect(ui->tableView->horizontalHeader(), &QHeaderView::sectionClicked, this, &AllUsers::onHeaderClicked);

    connect(pagination, &Pagination::updateCurrentPageInLabel, this, &AllUsers::updateCurrentPageInLabel);
    connect(pagination, &Pagination::setMaxPageInLabel, this, &AllUsers::setValueToMaxPage);
    connect(pagination, &Pagination::blockInterface, this, &AllUsers::blockingInterface);

    connect(workingIsTableView, &WorkingIsTableView::unlockInterface, this, &AllUsers::blockingInterface);

    connect(&goToPageTimer, &QTimer::timeout, this, [=]()
    {
        pagination->goToPage(ui->pageNumberToNavigate->text());
    });
}

void AllUsers::updateCurrentPageInLabel(int currentPage)
{
    ui->labelCurrentPage->setText(QString::number(currentPage));
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

void AllUsers::search()
{
    pagination->search(ui->searchText->text(), typeSearch, ui->searchColumn);
}

void AllUsers::selectTypeSearch(int arg)
{
    if(arg == 2)
        typeSearch.clear();
    else if(arg == 0)
        typeSearch = '%';

    search();
}

void AllUsers::sort()
{
    if(!sortingOn)
        return;

    pagination->refreshStartModel();
}

void AllUsers::sorting(int arg)
{
    sortingOn = (arg == 2) ? true : false;
    sort();
}

void AllUsers::onHeaderClicked(int logicalIndex)
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
