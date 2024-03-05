#include "activetables.h"
#include "ui_activetables.h"

ActiveTables::ActiveTables(QWidget *parent) :
    BaseClassSearchWindow(parent),
    ui(new Ui::ActiveTables)
{
    ui->setupUi(this);

    baseSetting();
}

ActiveTables::~ActiveTables()
{
    delete ui;
}

void ActiveTables::setValueToMaxPage(int maxPage)
{
    ui->labelMaxPage->setText(QString::number(maxPage));
}

void ActiveTables::assigningValues()
{
    boxsNameColumn.push_back(ui->searchColumn);
    boxsNameColumn.push_back(ui->sortingColumn);

    modelTypes = ModelTypes::ActiveTables;

    typeSearch = '%';
    sortingOn = false;

    goToPageTimer.setSingleShot(true);

    typesSorting =
    {
        {0, " ASC"},
        {1, " DESC"}
    };
}

void ActiveTables::creatingObjects()
{
    workingIsTableView = QSharedPointer<WorkingIsTableView>::create(ui->tableView, &boxsNameColumn);
    pagination = QSharedPointer<Pagination>::create(this, ui->tableView, ui->prevButton, ui->nextButton, workingIsTableView, modelTypes);

    addTable = QSharedPointer<Add_Table>::create();
}

void ActiveTables::connects()
{
    connect(ui->prevButton, &QPushButton::clicked, pagination.get(), &Pagination::prev);
    connect(ui->nextButton, &QPushButton::clicked, pagination.get(), &Pagination::next);
    connect(ui->pushButton_search, &QPushButton::clicked, this, &ActiveTables::search);
    connect(ui->addTable, &QPushButton::clicked, this, &ActiveTables::openCreatRecotd);
    connect(ui->editTable, &QPushButton::clicked, this, &ActiveTables::openEditRecotd);
    connect(ui->refreshData, &QPushButton::clicked, this, &ActiveTables::prepReloadModels);

    connect(ui->pageNumberToNavigate, &QLineEdit::textChanged, this, &ActiveTables::goToPage);
    connect(ui->searchText, &QLineEdit::textChanged, this, &ActiveTables::search);

    connect(ui->checkBox, &QCheckBox::stateChanged, this, &ActiveTables::selectTypeSearch);
    connect(ui->sorting, &QCheckBox::stateChanged, this, &ActiveTables::sorting);

    connect(ui->sortingColumn, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &ActiveTables::sort);
    connect(ui->typeSorting, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &ActiveTables::sort);

    connect(ui->tableView->horizontalHeader(), &QHeaderView::sectionClicked, this, &ActiveTables::onHeaderClicked);

    connect(pagination.get(), &Pagination::updateCurrentPageInLabel, this, &ActiveTables::updateCurrentPageInLabel);
    connect(pagination.get(), &Pagination::setMaxPageInLabel, this, &ActiveTables::setValueToMaxPage);
    connect(pagination.get(), &Pagination::blockInterface, this, &ActiveTables::blockingInterface);

    connect(workingIsTableView.get(), &WorkingIsTableView::unlockInterface, this, &ActiveTables::blockingInterface);

    connect(&goToPageTimer, &QTimer::timeout, this, [=]()
    {
        pagination->goToPage(ui->pageNumberToNavigate->text());
    });
}

void ActiveTables::updateCurrentPageInLabel(int currentPage)
{
    ui->labelCurrentPage->setText(QString::number(currentPage));
}

void ActiveTables::goToPage()
{
    if(ui->pageNumberToNavigate->text() == "0")
    {
        blockAndOperate(ui->pageNumberToNavigate, [&]() {ui->pageNumberToNavigate->clear();});
        return;
    }

    goToPageTimer.start(1000);
}

void ActiveTables::search()
{
    pagination->search(ui->searchText->text(), typeSearch, ui->searchColumn);
}

void ActiveTables::onHeaderClicked(int logicalIndex)
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

void ActiveTables::prepReloadModels()
{
    if(sortingOn)
    {
        QString column = ui->sortingColumn->currentText();
        QString typeSort = typesSorting[ui->typeSorting->currentIndex()];
        pagination->setSort("ORDER BY [" + column + "] " + typeSort);
    }
    else
        pagination->setSort("");

    ui->labelMaxPage->setText("????");
    ui->labelCurrentPage->setText("0");

    ui->pageNumberToNavigate->clear();

    pagination->reloadModels();
}

void ActiveTables::openCreatRecotd()
{
    addTable->show();
}

void ActiveTables::openEditRecotd()
{

}
