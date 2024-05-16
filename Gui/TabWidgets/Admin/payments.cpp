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
    BaseClassSearchWindow::assigningValues();

    boxsNameColumn.push_back(ui->searchColumn);
    boxsNameColumn.push_back(ui->sortingColumn);

    modelTypes = ModelTypes::Payments;
}

void Payments::creatingObjects()
{
    workingIsTableView = QSharedPointer<WorkingIsTableView>(new WorkingIsTableView(ui->tableView, &boxsNameColumn));
    pagination = QSharedPointer<Pagination>(new Pagination(this, ui->tableView, ui->searchColumn, workingIsTableView, modelTypes, ui->prevButton, ui->nextButton));
    filter = QSharedPointer<F_Payment>(new F_Payment());
}

void Payments::connects()
{
    BaseClassSearchWindow::connects();

    connect(ui->prevButton, &QPushButton::clicked, pagination.get(), &Pagination::prev);
    connect(ui->nextButton, &QPushButton::clicked, pagination.get(), &Pagination::next);
    connect(ui->pushButton_search, &QPushButton::clicked, this, &Payments::search);
    connect(ui->refreshData, &QPushButton::clicked, this, &Payments::prepReloadModels);
    connect(ui->clearSearch, &QPushButton::clicked, this, &Payments::clearSearchText);
    connect(ui->addFilter, &QPushButton::clicked, this, &Payments::addFilter);
    connect(ui->clearFilter, &QPushButton::clicked, this, &Payments::clearFilter);

    connect(ui->currentPage, &QLineEdit::textChanged, this, &Payments::goToPage);
    connect(ui->searchText, &QLineEdit::textChanged, this, &Payments::search);

    connect(ui->checkBox, &QCheckBox::stateChanged, this, &Payments::selectTypeSearch);
    connect(ui->sorting, &QCheckBox::stateChanged, this, &Payments::sorting);

    connect(ui->radioButton_Sorting, &QRadioButton::toggled, this, &Payments::visibleSort);
    connect(ui->radioButton_Search, &QRadioButton::toggled, this, &Payments::visibleSearch);
    connect(ui->radioButton_Filtr, &QRadioButton::toggled, this, &Payments::visibleFiltr);

    connect(ui->sortingColumn, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &Payments::sort);
    connect(ui->typeSorting, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &Payments::sort);

    connect(ui->tableView->horizontalHeader(), &QHeaderView::sectionClicked, this, &Payments::onHeaderClicked);
}

void Payments::updateCurrentPageInLabel(const int currentPage)
{
    blockAndOperate(ui->currentPage, [&]() {ui->currentPage->setText(QString::number(currentPage));});
}

void Payments::goToPage()
{
    if(ui->currentPage->text() == "0")
    {
        blockAndOperate(ui->currentPage, [&]() {ui->currentPage->clear();});
        return;
    }

    goToPageTimer.start(1000);
}

void Payments::search()
{
    searchTimer.start(500);
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

void Payments::visibleSort(const bool flag)
{
    ui->label_3->setVisible(flag);
    ui->label_2->setVisible(flag);
    ui->sortingColumn->setVisible(flag);
    ui->typeSorting->setVisible(flag);
    ui->sorting->setVisible(flag);
}

void Payments::visibleSearch(const bool flag)
{
    ui->label->setVisible(flag);
    ui->searchColumn->setVisible(flag);
    ui->searchText->setVisible(flag);
    ui->checkBox->setVisible(flag);
    ui->pushButton_search->setVisible(flag);
    ui->clearSearch->setVisible(flag);
}

void Payments::visibleEditing(const bool flag)
{
    Q_UNUSED(flag);
}

void Payments::visibleFiltr(const bool flag)
{
    ui->addFilter->setVisible(flag);
    ui->clearFilter->setVisible(flag);
}

void Payments::addFilter()
{
    if (filter->exec() == QDialog::Accepted)
    {

    }
}

void Payments::runSearch()
{
    pagination->search(ui->searchText->text(), typeSearch);
}

void Payments::runGoToPage()
{
    pagination->goToPage(ui->currentPage->text());
}
