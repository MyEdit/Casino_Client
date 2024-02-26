#include "existingtables.h"
#include "ui_existingtables.h"

ExistingTables::ExistingTables(QWidget *parent) :
    BaseClassSearchWindow(parent),
    ui(new Ui::ExistingTables)
{
    ui->setupUi(this);

    baseSetting();
}

ExistingTables::~ExistingTables()
{
    delete ui;
}

void ExistingTables::setValueToMaxPage(int maxPage)
{
    ui->labelMaxPage->setText(QString::number(maxPage));
}

void ExistingTables::assigningValues()
{
    boxsNameColumn.push_back(ui->searchColumn);
    boxsNameColumn.push_back(ui->sortingColumn);

    modelTypes = ModelTypes::TestTable;

    typeSearch = '%';
    sortingOn = false;

    goToPageTimer.setSingleShot(true);
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
    connect(ui->pushButton_search, &QPushButton::clicked, this, &ExistingTables::search);

    connect(ui->pageNumberToNavigate, &QLineEdit::textChanged, this, &ExistingTables::goToPage);
    connect(ui->searchText, &QLineEdit::textChanged, this, &ExistingTables::search);

    connect(ui->checkBox, &QCheckBox::stateChanged, this, &ExistingTables::selectTypeSearch);
    connect(ui->sorting, &QCheckBox::stateChanged, this, &ExistingTables::sorting);

    connect(ui->sortingColumn, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &ExistingTables::sort);
    connect(ui->typeSorting, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &ExistingTables::sort);

    connect(ui->tableView->horizontalHeader(), &QHeaderView::sectionClicked, this, &ExistingTables::onHeaderClicked);

    connect(pagination, &Pagination::updateCurrentPageInLabel, this, &ExistingTables::updateCurrentPageInLabel);
    connect(pagination, &Pagination::setMaxPageInLabel, this, &ExistingTables::setValueToMaxPage);
    connect(pagination, &Pagination::blockInterface, this, &ExistingTables::blockingInterface);

    connect(workingIsTableView, &WorkingIsTableView::unlockInterface, this, &ExistingTables::blockingInterface);

    connect(&goToPageTimer, &QTimer::timeout, this, [=]()
    {
        pagination->goToPage(ui->pageNumberToNavigate->text());
    });
}

void ExistingTables::updateCurrentPageInLabel(int currentPage)
{
    ui->labelCurrentPage->setText(QString::number(currentPage));
}

void ExistingTables::goToPage()
{
    if(ui->pageNumberToNavigate->text() == "0")
    {
        blockAndOperate(ui->pageNumberToNavigate, [&]() {ui->pageNumberToNavigate->clear();});
        return;
    }

    goToPageTimer.start(1000);
}

void ExistingTables::search()
{
    pagination->search(ui->searchText->text(), typeSearch, ui->searchColumn);
}

void ExistingTables::onHeaderClicked(int logicalIndex)
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
