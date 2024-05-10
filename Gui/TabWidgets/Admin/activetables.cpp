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

void ActiveTables::setValueToMaxPage(const int maxPage)
{
    ui->labelMaxPage->setText(QString::number(maxPage));
}

void ActiveTables::assigningValues()
{
    BaseClassSearchWindow::assigningValues();

    boxsNameColumn.push_back(ui->searchColumn);
    boxsNameColumn.push_back(ui->sortingColumn);

    modelTypes = ModelTypes::ActiveTables;
}

void ActiveTables::creatingObjects()
{
    workingIsTableView = QSharedPointer<WorkingIsTableView>(new WorkingIsTableView(ui->tableView, &boxsNameColumn));
    pagination = QSharedPointer<Pagination>(new Pagination(this, ui->tableView, ui->searchColumn, workingIsTableView, modelTypes));
    filter = QSharedPointer<F_Table>(new F_Table());
}

void ActiveTables::connects()
{
    connect(ui->prevButton, &QPushButton::clicked, pagination.get(), &Pagination::prev);
    connect(ui->nextButton, &QPushButton::clicked, pagination.get(), &Pagination::next);
    connect(ui->pushButton_search, &QPushButton::clicked, this, &ActiveTables::search);
    connect(ui->addTable, &QPushButton::clicked, this, &ActiveTables::openCreatRecotd);
    connect(ui->editTable, &QPushButton::clicked, this, &ActiveTables::openEditRecotd);
    connect(ui->deleteTable, &QPushButton::clicked, this, &ActiveTables::deleting);
    connect(ui->refreshData, &QPushButton::clicked, this, &ActiveTables::prepReloadModels);
    connect(ui->clearSearch, &QPushButton::clicked, this, &ActiveTables::clearSearchText);
    connect(ui->addFilter, &QPushButton::clicked, this, &ActiveTables::addFilter);
    connect(ui->clearFilter, &QPushButton::clicked, this, &ActiveTables::clearFilter);

    connect(ui->pageNumberToNavigate, &QLineEdit::textChanged, this, &ActiveTables::goToPage);
    connect(ui->searchText, &QLineEdit::textChanged, this, &ActiveTables::search);

    connect(ui->checkBox, &QCheckBox::stateChanged, this, &ActiveTables::selectTypeSearch);
    connect(ui->sorting, &QCheckBox::stateChanged, this, &ActiveTables::sorting);

    connect(ui->checkBox_Sorting, &QCheckBox::stateChanged, this, &ActiveTables::setVisibleSort);
    connect(ui->checkBox_Search, &QCheckBox::stateChanged, this, &ActiveTables::setVisibleSearch);
    connect(ui->checkBox_Editing, &QCheckBox::stateChanged, this, &ActiveTables::setVisibleEditing);
    connect(ui->checkBox_Filtr, &QCheckBox::stateChanged, this, &ActiveTables::setVisibleFiltr);

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

    connect(&searchTimer, &QTimer::timeout, this, [=]()
    {
        pagination->search(ui->searchText->text(), typeSearch);
    });
}

void ActiveTables::updateCurrentPageInLabel(const int currentPage)
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
    searchTimer.start(500);
}

void ActiveTables::onHeaderClicked(const int logicalIndex)
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
        ui->labelWhatKindSorting->setText(column + " по " + ui->typeSorting->currentText());
    }
    else
    {
        pagination->setSort("");
        ui->labelWhatKindSorting->setText("отсутствует");
    }

    ui->labelMaxPage->setText("????");
    ui->labelCurrentPage->setText("0");

    ui->pageNumberToNavigate->clear();



    pagination->reloadModels();
}

void ActiveTables::openCreatRecotd()
{
    workingWithTables = QSharedPointer<W_Table>::create(QueryTypes::CreateEntry);
    connect(workingWithTables.get(), &W_Table::update, pagination.get(), &Pagination::start);
    workingWithTables->show();
}

void ActiveTables::openEditRecotd()
{
    int id = getValueFromSelectedRow(ui->tableView, 1).toInt();
    QString maxPlayers = getValueFromSelectedRow(ui->tableView, 2).toString();
    QString minBet = getValueFromSelectedRow(ui->tableView, 3).toString();
    QString betStep = getValueFromSelectedRow(ui->tableView, 4).toString();
    QString minBalance = getValueFromSelectedRow(ui->tableView, 5).toString();
    QString nameGame = getValueFromSelectedRow(ui->tableView, 6).toString();

    QSharedPointer<ActiveTable> activeTable = QSharedPointer<ActiveTable>::create(id, maxPlayers, minBet, betStep, minBalance, nameGame);
    if (!activeTable->inputDataIsValid())
        return;

    workingWithTables = QSharedPointer<W_Table>::create(QueryTypes::UpdateEntry, activeTable);
    connect(workingWithTables.get(), &W_Table::update, pagination.get(), &Pagination::start);
    workingWithTables->show();
}

void ActiveTables::deleting()
{
    QString table = "ActiveTables";
    QString idColumn = "ID_Table";
    int id = getValueFromSelectedRow(ui->tableView, 1).toInt();

    deleteRecord(table, idColumn, id);
}

void ActiveTables::clearSearchText()
{
    ui->searchText->clear();
}

void ActiveTables::visibleSort(bool flag)
{
    ui->label_3->setVisible(flag);
    ui->label_2->setVisible(flag);
    ui->sortingColumn->setVisible(flag);
    ui->typeSorting->setVisible(flag);
    ui->sorting->setVisible(flag);
}

void ActiveTables::visibleSearch(bool flag)
{
    ui->label->setVisible(flag);
    ui->searchColumn->setVisible(flag);
    ui->searchText->setVisible(flag);
    ui->checkBox->setVisible(flag);
    ui->pushButton_search->setVisible(flag);
    ui->clearSearch->setVisible(flag);
}

void ActiveTables::visibleEditing(bool flag)
{
    ui->addTable->setVisible(flag);
    ui->editTable->setVisible(flag);
    ui->deleteTable->setVisible(flag);
}

void ActiveTables::visibleFiltr(bool flag)
{
    ui->addFilter->setVisible(flag);
    ui->clearFilter->setVisible(flag);
}

void ActiveTables::addFilter()
{
    if (filter->exec() == QDialog::Accepted)
    {

    }
}

void ActiveTables::clearFilter()
{

}
