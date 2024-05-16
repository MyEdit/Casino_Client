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

void BanList::setValueToMaxPage(const int maxPage)
{
    ui->labelMaxPage->setText(QString::number(maxPage));
}

void BanList::assigningValues()
{
    BaseClassSearchWindow::assigningValues();

    boxsNameColumn.push_back(ui->searchColumn);
    boxsNameColumn.push_back(ui->sortingColumn);

    modelTypes = ModelTypes::Banlist;
}

void BanList::creatingObjects()
{
    workingIsTableView = QSharedPointer<WorkingIsTableView>(new WorkingIsTableView(ui->tableView, &boxsNameColumn));
    pagination = QSharedPointer<Pagination>(new Pagination(this, ui->tableView, ui->searchColumn, workingIsTableView, modelTypes));
    filter = QSharedPointer<F_Ban>(new F_Ban());
}

void BanList::connects()
{
    BaseClassSearchWindow::connects();

    connect(ui->prevButton, &QPushButton::clicked, pagination.get(), &Pagination::prev);
    connect(ui->nextButton, &QPushButton::clicked, pagination.get(), &Pagination::next);
    connect(ui->pushButton_search, &QPushButton::clicked, this, &BanList::search);
    connect(ui->editBan, &QPushButton::clicked, this, &BanList::openEditRecotd);
    connect(ui->deleteBan, &QPushButton::clicked, this, &BanList::deleting);
    connect(ui->refreshData, &QPushButton::clicked, this, &BanList::prepReloadModels);
    connect(ui->clearSearch, &QPushButton::clicked, this, &BanList::clearSearchText);
    connect(ui->addFilter, &QPushButton::clicked, this, &BanList::addFilter);
    connect(ui->clearFilter, &QPushButton::clicked, this, &BanList::clearFilter);

    connect(ui->currentPage, &QLineEdit::textChanged, this, &BanList::goToPage);
    connect(ui->searchText, &QLineEdit::textChanged, this, &BanList::search);

    connect(ui->checkBox, &QCheckBox::stateChanged, this, &BanList::selectTypeSearch);
    connect(ui->sorting, &QCheckBox::stateChanged, this, &BanList::sorting);

    connect(ui->radioButton_Sorting, &QRadioButton::toggled, this, &BanList::visibleSort);
    connect(ui->radioButton_Search, &QRadioButton::toggled, this, &BanList::visibleSearch);
    connect(ui->radioButton_Editing, &QRadioButton::toggled, this, &BanList::visibleEditing);
    connect(ui->radioButton_Filtr, &QRadioButton::toggled, this, &BanList::visibleFiltr);

    connect(ui->sortingColumn, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &BanList::sort);
    connect(ui->typeSorting, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &BanList::sort);

    connect(ui->tableView->horizontalHeader(), &QHeaderView::sectionClicked, this, &BanList::onHeaderClicked);
}

void BanList::updateCurrentPageInLabel(const int currentPage)
{
    blockAndOperate(ui->currentPage, [&]() {ui->currentPage->setText(QString::number(currentPage));});
}

void BanList::goToPage()
{
    if(ui->currentPage->text() == "0")
    {
        blockAndOperate(ui->currentPage, [&]() {ui->currentPage->clear();});
        return;
    }

    goToPageTimer.start(1000);
}

void BanList::search()
{
    searchTimer.start(500);
}

void BanList::onHeaderClicked(const int logicalIndex)
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

void BanList::openEditRecotd()
{
    int id = getValueFromSelectedRow(ui->tableView, 1).toInt();
    QString fullName = getValueFromSelectedRow(ui->tableView, 2).toString();
    QString reason = getValueFromSelectedRow(ui->tableView, 3).toString();

    QSharedPointer<Ban> ban = QSharedPointer<Ban>::create(id, fullName, reason);
    if (!ban->inputDataIsValid())
        return;

    updateBan = QSharedPointer<W_Ban>::create(QueryTypes::UpdateEntry, ban);
    updateBan->show();
}

void BanList::deleting()
{   
    QString table = "Banlist";
    QString idColumn = "ID_User";
    int id = getValueFromSelectedRow(ui->tableView, 1).toInt();

    deleteRecord(table, idColumn, id);
}

void BanList::openCreatRecotd()
{

}

void BanList::clearSearchText()
{
    ui->searchText->clear();
}

void BanList::visibleSort(const bool flag)
{
    ui->label_3->setVisible(flag);
    ui->label_2->setVisible(flag);
    ui->sortingColumn->setVisible(flag);
    ui->typeSorting->setVisible(flag);
    ui->sorting->setVisible(flag);
}

void BanList::visibleSearch(const bool flag)
{
    ui->label->setVisible(flag);
    ui->searchColumn->setVisible(flag);
    ui->searchText->setVisible(flag);
    ui->checkBox->setVisible(flag);
    ui->pushButton_search->setVisible(flag);
    ui->clearSearch->setVisible(flag);
}

void BanList::visibleEditing(const bool flag)
{
    ui->editBan->setVisible(flag);
    ui->deleteBan->setVisible(flag);
}

void BanList::visibleFiltr(const bool flag)
{
    ui->addFilter->setVisible(flag);
    ui->clearFilter->setVisible(flag);
}

void BanList::addFilter()
{
    if (filter->exec() == QDialog::Accepted)
    {

    }
}

void BanList::runSearch()
{
    pagination->search(ui->searchText->text(), typeSearch);
}

void BanList::runGoToPage()
{
    pagination->goToPage(ui->currentPage->text());
}
