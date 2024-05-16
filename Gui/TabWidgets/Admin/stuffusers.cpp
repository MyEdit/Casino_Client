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
    BaseClassSearchWindow::assigningValues();

    boxsNameColumn.push_back(ui->searchColumn);
    boxsNameColumn.push_back(ui->sortingColumn);

    modelTypes = ModelTypes::StuffUsers;
}

void StuffUsers::creatingObjects()
{
    workingIsTableView = QSharedPointer<WorkingIsTableView>(new WorkingIsTableView(ui->tableView, &boxsNameColumn));
    pagination = QSharedPointer<Pagination>(new Pagination(this, ui->tableView, ui->searchColumn, workingIsTableView, modelTypes));
    filter = QSharedPointer<F_StuffUser>(new F_StuffUser());
}

void StuffUsers::connects()
{
    BaseClassSearchWindow::connects();

    connect(ui->prevButton, &QPushButton::clicked, pagination.get(), &Pagination::prev);
    connect(ui->nextButton, &QPushButton::clicked, pagination.get(), &Pagination::next);
    connect(ui->pushButton_search, &QPushButton::clicked, this, &StuffUsers::search);
    connect(ui->addStuffUser, &QPushButton::clicked, this, &StuffUsers::openCreatRecotd);
    connect(ui->editStuffUser, &QPushButton::clicked, this, &StuffUsers::openEditRecotd);
    connect(ui->deleteStuffUser, &QPushButton::clicked, this, &StuffUsers::deleting);
    connect(ui->refreshData, &QPushButton::clicked, this, &StuffUsers::prepReloadModels);
    connect(ui->clearSearch, &QPushButton::clicked, this, &StuffUsers::clearSearchText);
    connect(ui->addFilter, &QPushButton::clicked, this, &StuffUsers::addFilter);
    connect(ui->clearFilter, &QPushButton::clicked, this, &StuffUsers::clearFilter);

    connect(ui->currentPage, &QLineEdit::textChanged, this, &StuffUsers::goToPage);
    connect(ui->searchText, &QLineEdit::textChanged, this, &StuffUsers::search);

    connect(ui->checkBox, &QCheckBox::stateChanged, this, &StuffUsers::selectTypeSearch);
    connect(ui->sorting, &QCheckBox::stateChanged, this, &StuffUsers::sorting);

    connect(ui->radioButton_Sorting, &QRadioButton::toggled, this, &StuffUsers::visibleSort);
    connect(ui->radioButton_Search, &QRadioButton::toggled, this, &StuffUsers::visibleSearch);
    connect(ui->radioButton_Editing, &QRadioButton::toggled, this, &StuffUsers::visibleEditing);
    connect(ui->radioButton_Filtr, &QRadioButton::toggled, this, &StuffUsers::visibleFiltr);

    connect(ui->sortingColumn, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &StuffUsers::sort);
    connect(ui->typeSorting, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &StuffUsers::sort);

    connect(ui->tableView->horizontalHeader(), &QHeaderView::sectionClicked, this, &StuffUsers::onHeaderClicked);
}

void StuffUsers::updateCurrentPageInLabel(const int currentPage)
{
    blockAndOperate(ui->currentPage, [&]() {ui->currentPage->setText(QString::number(currentPage));});
}

void StuffUsers::goToPage()
{
    if(ui->currentPage->text() == "0")
    {
        blockAndOperate(ui->currentPage, [&]() {ui->currentPage->clear();});
        return;
    }

    goToPageTimer.start(1000);
}

void StuffUsers::search()
{
    searchTimer.start(500);
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

void StuffUsers::openCreatRecotd()
{
    workingWithStuffUsers = QSharedPointer<W_StuffUser>::create(QueryTypes::CreateEntry);
    workingWithStuffUsers->show();
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

    workingWithStuffUsers = QSharedPointer<W_StuffUser>::create(QueryTypes::UpdateEntry, stuffUser);
    workingWithStuffUsers->show();
}

void StuffUsers::deleting()
{
    QString table = "StuffUsers";
    QString idColumn = "ID_StuffUser";
    int id = getValueFromSelectedRow(ui->tableView, 1).toInt();

    deleteRecord(table, idColumn, id);
}

void StuffUsers::clearSearchText()
{
    ui->searchText->clear();
}

void StuffUsers::visibleSort(const bool flag)
{
    ui->label_3->setVisible(flag);
    ui->label_2->setVisible(flag);
    ui->sortingColumn->setVisible(flag);
    ui->typeSorting->setVisible(flag);
    ui->sorting->setVisible(flag);
}

void StuffUsers::visibleSearch(const bool flag)
{
    ui->label->setVisible(flag);
    ui->searchColumn->setVisible(flag);
    ui->searchText->setVisible(flag);
    ui->checkBox->setVisible(flag);
    ui->pushButton_search->setVisible(flag);
    ui->clearSearch->setVisible(flag);
}

void StuffUsers::visibleEditing(const bool flag)
{
    ui->addStuffUser->setVisible(flag);
    ui->editStuffUser->setVisible(flag);
    ui->deleteStuffUser->setVisible(flag);
}

void StuffUsers::visibleFiltr(const bool flag)
{
    ui->addFilter->setVisible(flag);
    ui->clearFilter->setVisible(flag);
}

void StuffUsers::addFilter()
{
    if (filter->exec() == QDialog::Accepted)
    {

    }
}

void StuffUsers::runSearch()
{
    pagination->search(ui->searchText->text(), typeSearch);
}

void StuffUsers::runGoToPage()
{
    pagination->goToPage(ui->currentPage->text());
}
