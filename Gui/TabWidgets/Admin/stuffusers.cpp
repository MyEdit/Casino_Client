#include "stuffusers.h"
#include "ui_stuffusers.h"

StuffUsers::StuffUsers(QWidget *parent) :
    BaseClassSearchWindow(parent),
    ui(new Ui::StuffUsers)
{
    ui->setupUi(this);

    baseSetting();
}

StuffUsers::~StuffUsers()
{
    delete ui;
}

void StuffUsers::setValueToMaxPage(const int maxPage)
{
    ui->labelMaxPage->setText(QString::number(maxPage));
}

void StuffUsers::assigningValues()
{
    boxsNameColumn.push_back(ui->searchColumn);
    boxsNameColumn.push_back(ui->sortingColumn);

    modelTypes = ModelTypes::StuffUsers;

    typeSearch = '%';
    sortingOn = false;

    goToPageTimer.setSingleShot(true);

    typesSorting =
    {
        {0, " ASC"},
        {1, " DESC"}
    };
}

void StuffUsers::creatingObjects()
{
    workingIsTableView = QSharedPointer<WorkingIsTableView>::create(ui->tableView, &boxsNameColumn);
    pagination = QSharedPointer<Pagination>::create(this, ui->tableView, ui->prevButton, ui->nextButton, ui->searchColumn, workingIsTableView, modelTypes);
}

void StuffUsers::connects()
{
    connect(ui->prevButton, &QPushButton::clicked, pagination.get(), &Pagination::prev);
    connect(ui->nextButton, &QPushButton::clicked, pagination.get(), &Pagination::next);
    connect(ui->pushButton_search, &QPushButton::clicked, this, &StuffUsers::search);
    connect(ui->addStuffUser, &QPushButton::clicked, this, &StuffUsers::openCreatRecotd);
    connect(ui->editStuffUser, &QPushButton::clicked, this, &StuffUsers::openEditRecotd);
    connect(ui->deleteStuffUser, &QPushButton::clicked, this, &StuffUsers::deleting);
    connect(ui->refreshData, &QPushButton::clicked, this, &StuffUsers::prepReloadModels);

    connect(ui->pageNumberToNavigate, &QLineEdit::textChanged, this, &StuffUsers::goToPage);
    connect(ui->searchText, &QLineEdit::textChanged, this, &StuffUsers::search);

    connect(ui->checkBox, &QCheckBox::stateChanged, this, &StuffUsers::selectTypeSearch);
    connect(ui->sorting, &QCheckBox::stateChanged, this, &StuffUsers::sorting);

    connect(ui->sortingColumn, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &StuffUsers::sort);
    connect(ui->typeSorting, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &StuffUsers::sort);

    connect(ui->tableView->horizontalHeader(), &QHeaderView::sectionClicked, this, &StuffUsers::onHeaderClicked);

    connect(pagination.get(), &Pagination::updateCurrentPageInLabel, this, &StuffUsers::updateCurrentPageInLabel);
    connect(pagination.get(), &Pagination::setMaxPageInLabel, this, &StuffUsers::setValueToMaxPage);
    connect(pagination.get(), &Pagination::blockInterface, this, &StuffUsers::blockingInterface);

    connect(workingIsTableView.get(), &WorkingIsTableView::unlockInterface, this, &StuffUsers::blockingInterface);

    connect(&goToPageTimer, &QTimer::timeout, this, [=]()
    {
        pagination->goToPage(ui->pageNumberToNavigate->text());
    });
}

void StuffUsers::updateCurrentPageInLabel(const int currentPage)
{
    ui->labelCurrentPage->setText(QString::number(currentPage));
}

void StuffUsers::goToPage()
{
    if(ui->pageNumberToNavigate->text() == "0")
    {
        blockAndOperate(ui->pageNumberToNavigate, [&]() {ui->pageNumberToNavigate->clear();});
        return;
    }

    goToPageTimer.start(1000);
}

void StuffUsers::search()
{
    pagination->search(ui->searchText->text(), typeSearch);
}

void StuffUsers::onHeaderClicked(const int logicalIndex)
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

void StuffUsers::prepReloadModels()
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

void StuffUsers::openCreatRecotd()
{
    addStuffUser = QSharedPointer<W_StuffUser>::create(QueryTypes::CreateEntry);
    addStuffUser->show();
}

void StuffUsers::openEditRecotd()
{
    int id = getValueFromSelectedRow(ui->tableView, 1).toInt();
    QString fullName = getValueFromSelectedRow(ui->tableView, 2).toString();
    QString login = getValueFromSelectedRow(ui->tableView, 3).toString();
    QString password = getValueFromSelectedRow(ui->tableView, 4).toString();
    Roles role = static_cast<Roles>(getValueFromSelectedRow(ui->tableView, 5).toInt());

    QSharedPointer<ObjectStuffUser> stuffUser = QSharedPointer<ObjectStuffUser>::create(id, fullName, login, password, role);
    if (!stuffUser->inputDataIsValid())
        return;

    updateStuffUser = QSharedPointer<W_StuffUser>::create(QueryTypes::UpdateEntry, stuffUser);
    updateStuffUser->show();
}

void StuffUsers::deleting()
{
    QString table = "StuffUsers";
    QString idColumn = "ID_StuffUser";
    int id = getValueFromSelectedRow(ui->tableView, 1).toInt();

    deleteRecord(table, idColumn, id);
}
