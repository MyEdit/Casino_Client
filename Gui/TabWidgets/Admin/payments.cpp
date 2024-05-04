#include "payments.h"
#include "ui_payments.h"

Payments::Payments(QWidget *parent) :
    BaseClassSearchWindow(parent),
    ui(new Ui::Payments)
{
    ui->setupUi(this);

    baseSetting();
}

Payments::~Payments()
{
    delete ui;
}

void Payments::setValueToMaxPage(const int maxPage)
{
    ui->labelMaxPage->setText(QString::number(maxPage));
}

void Payments::assigningValues()
{
    boxsNameColumn.push_back(ui->searchColumn);
    boxsNameColumn.push_back(ui->sortingColumn);

    modelTypes = ModelTypes::Payments;

    typeSearch = '%';
    sortingOn = false;

    goToPageTimer.setSingleShot(true);

    typesSorting =
    {
        {0, "ASC"},
        {1, "DESC"}
    };
}

void Payments::creatingObjects()
{
    workingIsTableView = QSharedPointer<WorkingIsTableView>(new WorkingIsTableView(ui->tableView, &boxsNameColumn));
    pagination = QSharedPointer<Pagination>(new Pagination(this, ui->tableView, ui->searchColumn, workingIsTableView, modelTypes));
}

void Payments::connects()
{
    connect(ui->prevButton, &QPushButton::clicked, pagination.get(), &Pagination::prev);
    connect(ui->nextButton, &QPushButton::clicked, pagination.get(), &Pagination::next);
    connect(ui->pushButton_search, &QPushButton::clicked, this, &Payments::search);
    connect(ui->addPayments, &QPushButton::clicked, this, &Payments::openCreatRecotd);
    connect(ui->editPayments, &QPushButton::clicked, this, &Payments::openEditRecotd);
    connect(ui->deletePayments, &QPushButton::clicked, this, &Payments::deleting);
    connect(ui->refreshData, &QPushButton::clicked, this, &Payments::prepReloadModels);
    connect(ui->clearSearch, &QPushButton::clicked, this, &Payments::clearSearchText);

    connect(ui->pageNumberToNavigate, &QLineEdit::textChanged, this, &Payments::goToPage);
    connect(ui->searchText, &QLineEdit::textChanged, this, &Payments::search);

    connect(ui->checkBox, &QCheckBox::stateChanged, this, &Payments::selectTypeSearch);
    connect(ui->sorting, &QCheckBox::stateChanged, this, &Payments::sorting);

    connect(ui->sortingColumn, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &Payments::sort);
    connect(ui->typeSorting, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &Payments::sort);

    connect(ui->tableView->horizontalHeader(), &QHeaderView::sectionClicked, this, &Payments::onHeaderClicked);

    connect(pagination.get(), &Pagination::updateCurrentPageInLabel, this, &Payments::updateCurrentPageInLabel);
    connect(pagination.get(), &Pagination::setMaxPageInLabel, this, &Payments::setValueToMaxPage);
    connect(pagination.get(), &Pagination::blockInterface, this, &Payments::blockingInterface);

    connect(workingIsTableView.get(), &WorkingIsTableView::unlockInterface, this, &Payments::blockingInterface);

    connect(&goToPageTimer, &QTimer::timeout, this, [=]()
    {
        pagination->goToPage(ui->pageNumberToNavigate->text());
    });
}

void Payments::updateCurrentPageInLabel(const int currentPage)
{
    ui->labelCurrentPage->setText(QString::number(currentPage));
}

void Payments::goToPage()
{
    if(ui->pageNumberToNavigate->text() == "0")
    {
        blockAndOperate(ui->pageNumberToNavigate, [&]() {ui->pageNumberToNavigate->clear();});
        return;
    }

    goToPageTimer.start(1000);
}

void Payments::search()
{
    pagination->search(ui->searchText->text(), typeSearch);
}

void Payments::onHeaderClicked(const int logicalIndex)
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

void Payments::prepReloadModels()
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

void Payments::openCreatRecotd()
{

}

void Payments::openEditRecotd()
{

}

void Payments::deleting()
{
    QString table = "Payments";
    QString idColumn = "ID_Payment";
    int id = getValueFromSelectedRow(ui->tableView, 1).toInt();

    deleteRecord(table, idColumn, id);
}

void Payments::clearSearchText()
{
    ui->searchText->clear();
}
