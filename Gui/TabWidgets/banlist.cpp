#include "banlist.h"
#include "ui_banlist.h"

BanList::BanList(QWidget *parent) :
    BaseClassSearchWindow(parent),
    ui(new Ui::BanList)
{
    ui->setupUi(this);

    baseSetting();
}

BanList::~BanList()
{
    delete ui;
}

void BanList::setValueToMaxPage(int maxPage)
{
    ui->labelMaxPage->setText(QString::number(maxPage));
}

void BanList::assigningValues()
{
    boxsNameColumn.push_back(ui->searchColumn);
    boxsNameColumn.push_back(ui->sortingColumn);

    modelTypes = ModelTypes::Banlist;

    typeSearch = '%';
    sortingOn = false;

    goToPageTimer.setSingleShot(true);

    typesSorting =
    {
        {0, " ASC"},
        {1, " DESC"}
    };
}

void BanList::creatingObjects()
{
    workingIsTableView = QSharedPointer<WorkingIsTableView>::create(ui->tableView, &boxsNameColumn);
    pagination = QSharedPointer<Pagination>::create(this, ui->tableView, ui->prevButton, ui->nextButton, workingIsTableView, modelTypes);

    addBan = QSharedPointer<Add_Ban>::create();
}

void BanList::connects()
{
    connect(ui->prevButton, &QPushButton::clicked, pagination.get(), &Pagination::prev);
    connect(ui->nextButton, &QPushButton::clicked, pagination.get(), &Pagination::next);
    connect(ui->pushButton_search, &QPushButton::clicked, this, &BanList::search);
    connect(ui->addBan, &QPushButton::clicked, this, &BanList::openCreatRecotd);
    connect(ui->editBan, &QPushButton::clicked, this, &BanList::openEditRecotd);
    connect(ui->refreshData, &QPushButton::clicked, this, &BanList::prepReloadModels);

    connect(ui->pageNumberToNavigate, &QLineEdit::textChanged, this, &BanList::goToPage);
    connect(ui->searchText, &QLineEdit::textChanged, this, &BanList::search);

    connect(ui->checkBox, &QCheckBox::stateChanged, this, &BanList::selectTypeSearch);
    connect(ui->sorting, &QCheckBox::stateChanged, this, &BanList::sorting);

    connect(ui->sortingColumn, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &BanList::sort);
    connect(ui->typeSorting, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &BanList::sort);

    connect(ui->tableView->horizontalHeader(), &QHeaderView::sectionClicked, this, &BanList::onHeaderClicked);

    connect(pagination.get(), &Pagination::updateCurrentPageInLabel, this, &BanList::updateCurrentPageInLabel);
    connect(pagination.get(), &Pagination::setMaxPageInLabel, this, &BanList::setValueToMaxPage);
    connect(pagination.get(), &Pagination::blockInterface, this, &BanList::blockingInterface);

    connect(workingIsTableView.get(), &WorkingIsTableView::unlockInterface, this, &BanList::blockingInterface);

    connect(&goToPageTimer, &QTimer::timeout, this, [=]()
    {
        pagination->goToPage(ui->pageNumberToNavigate->text());
    });
}

void BanList::updateCurrentPageInLabel(int currentPage)
{
    ui->labelCurrentPage->setText(QString::number(currentPage));
}

void BanList::goToPage()
{
    if(ui->pageNumberToNavigate->text() == "0")
    {
        blockAndOperate(ui->pageNumberToNavigate, [&]() {ui->pageNumberToNavigate->clear();});
        return;
    }

    goToPageTimer.start(1000);
}

void BanList::search()
{
    pagination->search(ui->searchText->text(), typeSearch, ui->searchColumn);
}

void BanList::onHeaderClicked(int logicalIndex)
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

void BanList::prepReloadModels()
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

void BanList::openCreatRecotd()
{
    addBan->show();
}

void BanList::openEditRecotd()
{

}
