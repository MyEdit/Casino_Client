#include "profit.h"
#include "ui_profit.h"

Profit::Profit(QWidget *parent) :
    BaseClassSearchWindow(parent),
    ui(new Ui::Profit)
{
    ui->setupUi(this);
    baseSetting();
    requestAmountProfit();
}

Profit::~Profit()
{
    delete ui;
}

void Profit::setValueToMaxPage(const int maxPage)
{
    ui->labelMaxPage->setText(QString::number(maxPage));
}

void Profit::assigningValues()
{
    BaseClassSearchWindow::assigningValues();

    boxsNameColumn.push_back(ui->searchColumn);
    boxsNameColumn.push_back(ui->sortingColumn);

    modelTypes = ModelTypes::Profit;
}

void Profit::creatingObjects()
{
    workingIsTableView = QSharedPointer<WorkingIsTableView>(new WorkingIsTableView(ui->tableView, &boxsNameColumn));
    pagination = QSharedPointer<Pagination>(new Pagination(this, ui->tableView, ui->searchColumn, workingIsTableView, modelTypes, ui->prevButton, ui->nextButton));
    filter = QSharedPointer<F_Profit>(new F_Profit());
}

void Profit::connects()
{
    BaseClassSearchWindow::connects();

    connect(ui->prevButton, &QPushButton::clicked, pagination.get(), &Pagination::prev);
    connect(ui->nextButton, &QPushButton::clicked, pagination.get(), &Pagination::next);
    connect(ui->pushButton_search, &QPushButton::clicked, this, &Profit::search);
    connect(ui->refreshData, &QPushButton::clicked, this, &Profit::prepReloadModels);
    connect(ui->clearSearch, &QPushButton::clicked, this, &Profit::clearSearchText);
    connect(ui->addFilter, &QPushButton::clicked, this, &Profit::addFilter);
    connect(ui->clearFilter, &QPushButton::clicked, this, &Profit::clearFilter);

    connect(ui->currentPage, &QLineEdit::textChanged, this, &Profit::goToPage);
    connect(ui->searchText, &QLineEdit::textChanged, this, &Profit::search);

    connect(ui->checkBox, &QCheckBox::stateChanged, this, &Profit::selectTypeSearch);
    connect(ui->sorting, &QCheckBox::stateChanged, this, &Profit::sorting);

    connect(ui->radioButton_Sorting, &QRadioButton::toggled, this, &Profit::visibleSort);
    connect(ui->radioButton_Search, &QRadioButton::toggled, this, &Profit::visibleSearch);
    connect(ui->radioButton_Filtr, &QRadioButton::toggled, this, &Profit::visibleFiltr);

    connect(ui->sortingColumn, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &Profit::sort);
    connect(ui->typeSorting, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &Profit::sort);

    connect(ui->tableView->horizontalHeader(), &QHeaderView::sectionClicked, this, &Profit::onHeaderClicked);

    connect(NetworkClient::packetHandler, &PacketHandler::signalSetQueryModel, this, &Profit::distributor);
}

void Profit::updateCurrentPageInLabel(const int currentPage)
{
    blockAndOperate(ui->currentPage, [&]() {ui->currentPage->setText(QString::number(currentPage));});
}

void Profit::goToPage()
{
    if(ui->currentPage->text() == "0")
    {
        blockAndOperate(ui->currentPage, [&]() {ui->currentPage->clear();});
        return;
    }

    goToPageTimer.start(1000);
}

void Profit::search()
{
    searchTimer.start(500);
}

void Profit::onHeaderClicked(const int logicalIndex)
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

void Profit::prepReloadModels()
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

    requestAmountProfit();
    pagination->reloadModels();
}

void Profit::openCreatRecotd()
{

}

void Profit::openEditRecotd()
{

}

void Profit::deleting()
{
    QString table = "Profit";
    QString idColumn = "ID_Table";
    int id = getValueFromSelectedRow(ui->tableView, 1).toInt();

    deleteRecord(table, idColumn, id);
}

void Profit::clearSearchText()
{
    ui->searchText->clear();
}

void Profit::visibleSort(const bool flag)
{
    ui->label_3->setVisible(flag);
    ui->label_2->setVisible(flag);
    ui->sortingColumn->setVisible(flag);
    ui->typeSorting->setVisible(flag);
    ui->sorting->setVisible(flag);
}

void Profit::visibleSearch(const bool flag)
{
    ui->label->setVisible(flag);
    ui->searchColumn->setVisible(flag);
    ui->searchText->setVisible(flag);
    ui->checkBox->setVisible(flag);
    ui->pushButton_search->setVisible(flag);
    ui->clearSearch->setVisible(flag);
}

void Profit::visibleEditing(const bool flag)
{
    Q_UNUSED(flag);
}

void Profit::visibleFiltr(const bool flag)
{
    ui->addFilter->setVisible(flag);
    ui->clearFilter->setVisible(flag);
}

void Profit::addFilter()
{
    if (filter->exec() == QDialog::Accepted)
    {

    }
}

void Profit::runSearch()
{
    pagination->search(ui->searchText->text(), typeSearch);
}

void Profit::runGoToPage()
{
    pagination->goToPage(ui->currentPage->text());
}

void Profit::setAmoutProfit(QString amout)
{
    ui->amoutProfit->setText(amout);
}

void Profit::requestAmountProfit()
{
    PacketTypes packettype = PacketTypes::P_Query;
    QString query = "SELECT round(sum([Сумма]), 2) from Profit_pred where 1=1 " + pagination->getWhere();
    QueryTypes queryTypes = QueryTypes::Other;

    NetworkClient::sendToServer(&packettype, sizeof(PacketTypes));
    NetworkClient::sendToServer(&queryTypes, sizeof(QueryTypes));
    NetworkClient::sendToServer(&modelTypes, sizeof(ModelTypes));
    NetworkClient::sendToServer(query);
}

void Profit::distributor(QSharedPointer<QueryData> data)
{
    if(data->modelTypes != modelTypes)
        return;

    if(data->queryTypes != QueryTypes::Other)
        return;

    setAmoutProfit(data->result);
}

void Profit::update()
{
    BaseClassSearchWindow::update();
    requestAmountProfit();
}
