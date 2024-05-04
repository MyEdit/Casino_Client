#include "users.h"
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
    boxsNameColumn.push_back(ui->searchColumn);
    boxsNameColumn.push_back(ui->sortingColumn);

    modelTypes = ModelTypes::Users;

    typeSearch = '%';
    sortingOn = false;

    goToPageTimer.setSingleShot(true);

    typesSorting =
    {
        {0, "ASC"},
        {1, "DESC"}
    };
}

void Users::creatingObjects()
{
    workingIsTableView = QSharedPointer<WorkingIsTableView>(new WorkingIsTableView(ui->tableView, &boxsNameColumn));
    pagination = QSharedPointer<Pagination>(new Pagination(this, ui->tableView, ui->searchColumn, workingIsTableView, modelTypes));
}

void Users::connects()
{
    connect(ui->prevButton, &QPushButton::clicked, pagination.get(), &Pagination::prev);
    connect(ui->nextButton, &QPushButton::clicked, pagination.get(), &Pagination::next);
    connect(ui->pushButton_search, &QPushButton::clicked, this, &Users::search);
    connect(ui->addUser, &QPushButton::clicked, this, &Users::openCreatRecotd);
    connect(ui->editUser, &QPushButton::clicked, this, &Users::openEditRecotd);
    connect(ui->deleteUser, &QPushButton::clicked, this, &Users::deleting);
    connect(ui->refreshData, &QPushButton::clicked, this, &Users::prepReloadModels);
    connect(ui->addBun, &QPushButton::clicked, this, &Users::openCreateBan);
    connect(ui->clearSearch, &QPushButton::clicked, this, &Users::clearSearchText);

    connect(ui->pageNumberToNavigate, &QLineEdit::textChanged, this, &Users::goToPage);
    connect(ui->searchText, &QLineEdit::textChanged, this, &Users::search);

    connect(ui->checkBox, &QCheckBox::stateChanged, this, &Users::selectTypeSearch);
    connect(ui->sorting, &QCheckBox::stateChanged, this, &Users::sorting);

    connect(ui->sortingColumn, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &Users::sort);
    connect(ui->typeSorting, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &Users::sort);

    connect(ui->tableView->horizontalHeader(), &QHeaderView::sectionClicked, this, &Users::onHeaderClicked);

    connect(pagination.get(), &Pagination::updateCurrentPageInLabel, this, &Users::updateCurrentPageInLabel);
    connect(pagination.get(), &Pagination::setMaxPageInLabel, this, &Users::setValueToMaxPage);
    connect(pagination.get(), &Pagination::blockInterface, this, &Users::blockingInterface);

    connect(workingIsTableView.get(), &WorkingIsTableView::unlockInterface, this, &Users::blockingInterface);

    connect(&goToPageTimer, &QTimer::timeout, this, [=]()
    {
        pagination->goToPage(ui->pageNumberToNavigate->text());
    });
}

void Users::updateCurrentPageInLabel(const int currentPage)
{
    ui->labelCurrentPage->setText(QString::number(currentPage));
}

void Users::goToPage()
{
    if(ui->pageNumberToNavigate->text() == "0")
    {
        blockAndOperate(ui->pageNumberToNavigate, [&]() {ui->pageNumberToNavigate->clear();});
        return;
    }

    goToPageTimer.start(1000);
}

void Users::search()
{
    pagination->search(ui->searchText->text(), typeSearch);
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
    }
    else
        pagination->setSort("");

    ui->labelMaxPage->setText("????");
    ui->labelCurrentPage->setText("0");

    ui->pageNumberToNavigate->clear();

    pagination->reloadModels();
}

void Users::openCreatRecotd()
{
    addUser = QSharedPointer<W_User>::create(QueryTypes::CreateEntry);
    addUser->show();
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

    updateUser = QSharedPointer<W_User>::create(QueryTypes::UpdateEntry, user);
    updateUser->show();
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
