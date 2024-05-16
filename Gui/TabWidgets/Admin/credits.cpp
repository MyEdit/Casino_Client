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
    BaseClassSearchWindow::assigningValues();

    boxsNameColumn.push_back(ui->searchColumn);
    boxsNameColumn.push_back(ui->sortingColumn);

    modelTypes = ModelTypes::Credits;
}

void Credits::creatingObjects()
{
    workingIsTableView = QSharedPointer<WorkingIsTableView>(new WorkingIsTableView(ui->tableView, &boxsNameColumn));
    pagination = QSharedPointer<Pagination>(new Pagination(this, ui->tableView, ui->searchColumn, workingIsTableView, modelTypes));
    filter = QSharedPointer<F_Credit>(new F_Credit());
}

void Credits::connects()
{
    BaseClassSearchWindow::connects();

    connect(ui->prevButton, &QPushButton::clicked, pagination.get(), &Pagination::prev);
    connect(ui->nextButton, &QPushButton::clicked, pagination.get(), &Pagination::next);
    connect(ui->pushButton_search, &QPushButton::clicked, this, &Credits::search);
    connect(ui->addCredit, &QPushButton::clicked, this, &Credits::openCreatRecotd);
    connect(ui->editCredit, &QPushButton::clicked, this, &Credits::openEditRecotd);
    connect(ui->deleteCredit, &QPushButton::clicked, this, &Credits::deleting);
    connect(ui->refreshData, &QPushButton::clicked, this, &Credits::prepReloadModels);
    connect(ui->clearSearch, &QPushButton::clicked, this, &Credits::clearSearchText);
    connect(ui->addFilter, &QPushButton::clicked, this, &Credits::addFilter);
    connect(ui->clearFilter, &QPushButton::clicked, this, &Credits::clearFilter);

    connect(ui->currentPage, &QLineEdit::textChanged, this, &Credits::goToPage);
    connect(ui->searchText, &QLineEdit::textChanged, this, &Credits::search);

    connect(ui->radioButton_Sorting, &QRadioButton::toggled, this, &Credits::visibleSort);
    connect(ui->radioButton_Search, &QRadioButton::toggled, this, &Credits::visibleSearch);
    connect(ui->radioButton_Editing, &QRadioButton::toggled, this, &Credits::visibleEditing);
    connect(ui->radioButton_Filtr, &QRadioButton::toggled, this, &Credits::visibleFiltr);

    connect(ui->checkBox, &QCheckBox::stateChanged, this, &Credits::selectTypeSearch);
    connect(ui->sorting, &QCheckBox::stateChanged, this, &Credits::sorting);

    connect(ui->sortingColumn, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &Credits::sort);
    connect(ui->typeSorting, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &Credits::sort);

    connect(ui->tableView->horizontalHeader(), &QHeaderView::sectionClicked, this, &Credits::onHeaderClicked);
}

void Credits::updateCurrentPageInLabel(const int currentPage)
{
    blockAndOperate(ui->currentPage, [&]() {ui->currentPage->setText(QString::number(currentPage));});
}

void Credits::goToPage()
{
    if(ui->currentPage->text() == "0")
    {
        blockAndOperate(ui->currentPage, [&]() {ui->currentPage->clear();});
        return;
    }

    goToPageTimer.start(1000);
}

void Credits::search()
{
    searchTimer.start(500);
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

void Credits::openCreatRecotd()
{

}

void Credits::openEditRecotd()
{

}

void Credits::deleting()
{

}

void Credits::clearSearchText()
{
    ui->searchText->clear();
}

void Credits::visibleSort(const bool flag)
{
    ui->label_3->setVisible(flag);
    ui->label_2->setVisible(flag);
    ui->sortingColumn->setVisible(flag);
    ui->typeSorting->setVisible(flag);
    ui->sorting->setVisible(flag);
}

void Credits::visibleSearch(const bool flag)
{
    ui->label->setVisible(flag);
    ui->searchColumn->setVisible(flag);
    ui->searchText->setVisible(flag);
    ui->checkBox->setVisible(flag);
    ui->pushButton_search->setVisible(flag);
    ui->clearSearch->setVisible(flag);
}

void Credits::visibleEditing(const bool flag)
{
    ui->addCredit->setVisible(flag);
    ui->editCredit->setVisible(flag);
    ui->deleteCredit->setVisible(flag);
}

void Credits::visibleFiltr(const bool flag)
{
    ui->addFilter->setVisible(flag);
    ui->clearFilter->setVisible(flag);
}

void Credits::addFilter()
{
    if (filter->exec() == QDialog::Accepted)
    {

    }
}

void Credits::runSearch()
{
    pagination->search(ui->searchText->text(), typeSearch);
}

void Credits::runGoToPage()
{
    pagination->goToPage(ui->currentPage->text());
}
