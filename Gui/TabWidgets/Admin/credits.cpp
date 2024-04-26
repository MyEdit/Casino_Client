#include "credits.h"
#include "ui_credits.h"

Credits::Credits(QWidget *parent) :
    BaseClassSearchWindow(parent),
    ui(new Ui::Credits)
{
    ui->setupUi(this);

    baseSetting();
}

Credits::~Credits()
{
    delete ui;
}

void Credits::setValueToMaxPage(const int maxPage)
{
    ui->labelMaxPage->setText(QString::number(maxPage));
}

void Credits::assigningValues()
{
    boxsNameColumn.push_back(ui->searchColumn);
    boxsNameColumn.push_back(ui->sortingColumn);

    modelTypes = ModelTypes::Credits;

    typeSearch = '%';
    sortingOn = false;

    goToPageTimer.setSingleShot(true);

    typesSorting =
    {
        {0, "ASC"},
        {1, "DESC"}
    };
}

void Credits::creatingObjects()
{
    workingIsTableView = QSharedPointer<WorkingIsTableView>::create(ui->tableView, &boxsNameColumn);
    pagination = QSharedPointer<Pagination>::create(this, ui->tableView, ui->prevButton, ui->nextButton, ui->searchColumn, workingIsTableView, modelTypes);
}

void Credits::connects()
{
    connect(ui->prevButton, &QPushButton::clicked, pagination.get(), &Pagination::prev);
    connect(ui->nextButton, &QPushButton::clicked, pagination.get(), &Pagination::next);
    connect(ui->pushButton_search, &QPushButton::clicked, this, &Credits::search);
    connect(ui->addCredit, &QPushButton::clicked, this, &Credits::openCreatRecotd);
    connect(ui->editCredit, &QPushButton::clicked, this, &Credits::openEditRecotd);
    connect(ui->deleteCredit, &QPushButton::clicked, this, &Credits::deleting);
    connect(ui->refreshData, &QPushButton::clicked, this, &Credits::prepReloadModels);

    connect(ui->pageNumberToNavigate, &QLineEdit::textChanged, this, &Credits::goToPage);
    connect(ui->searchText, &QLineEdit::textChanged, this, &Credits::search);

    connect(ui->checkBox, &QCheckBox::stateChanged, this, &Credits::selectTypeSearch);
    connect(ui->sorting, &QCheckBox::stateChanged, this, &Credits::sorting);

    connect(ui->sortingColumn, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &Credits::sort);
    connect(ui->typeSorting, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &Credits::sort);

    connect(ui->tableView->horizontalHeader(), &QHeaderView::sectionClicked, this, &Credits::onHeaderClicked);

    connect(pagination.get(), &Pagination::updateCurrentPageInLabel, this, &Credits::updateCurrentPageInLabel);
    connect(pagination.get(), &Pagination::setMaxPageInLabel, this, &Credits::setValueToMaxPage);
    connect(pagination.get(), &Pagination::blockInterface, this, &Credits::blockingInterface);

    connect(workingIsTableView.get(), &WorkingIsTableView::unlockInterface, this, &Credits::blockingInterface);

    connect(&goToPageTimer, &QTimer::timeout, this, [=]()
    {
        pagination->goToPage(ui->pageNumberToNavigate->text());
    });
}

void Credits::updateCurrentPageInLabel(const int currentPage)
{
    ui->labelCurrentPage->setText(QString::number(currentPage));
}

void Credits::goToPage()
{
    if(ui->pageNumberToNavigate->text() == "0")
    {
        blockAndOperate(ui->pageNumberToNavigate, [&]() {ui->pageNumberToNavigate->clear();});
        return;
    }

    goToPageTimer.start(1000);
}

void Credits::search()
{
    pagination->search(ui->searchText->text(), typeSearch);
}

void Credits::onHeaderClicked(const int logicalIndex)
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

void Credits::prepReloadModels()
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

void Credits::openCreatRecotd()
{

}

void Credits::openEditRecotd()
{

}

void Credits::deleting()
{
    QString table = "Credits";
    QString idColumn = "ID_Credit";
    int id = getValueFromSelectedRow(ui->tableView, 1).toInt();

    deleteRecord(table, idColumn, id);
}
