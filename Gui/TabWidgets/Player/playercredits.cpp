#include "playercredits.h"
#include "ui_playercredits.h"

PlayerCredits::PlayerCredits(QWidget *parent) :
    BaseClassSearchWindow(parent),
    ui(new Ui::PlayerCredits)
{
    ui->setupUi(this);

    baseSetting();

    defaultFilter = "and ID_User = '" + QString::number(P_Authorization::getPlayer()->getID()) + "'";
    pagination->setWhere(defaultFilter);
}

PlayerCredits::~PlayerCredits()
{
    delete ui;
}

void PlayerCredits::setValueToMaxPage(const int maxPage)
{
    ui->labelMaxPage->setText(QString::number(maxPage));
}

void PlayerCredits::assigningValues()
{
    BaseClassSearchWindow::assigningValues();

    boxsNameColumn.push_back(ui->searchColumn);
    boxsNameColumn.push_back(ui->sortingColumn);

    modelTypes = ModelTypes::Credits;
}

void PlayerCredits::creatingObjects()
{
    workingIsTableView = QSharedPointer<WorkingIsTableView>(new WorkingIsTableView(ui->tableView, &boxsNameColumn));
    pagination = QSharedPointer<Pagination>(new Pagination(this, ui->tableView, ui->searchColumn, workingIsTableView, modelTypes));
    filter = QSharedPointer<F_PlayerCredit>(new F_PlayerCredit());
}

void PlayerCredits::connects()
{
    BaseClassSearchWindow::connects();

    connect(ui->prevButton, &QPushButton::clicked, pagination.get(), &Pagination::prev);
    connect(ui->nextButton, &QPushButton::clicked, pagination.get(), &Pagination::next);
    connect(ui->pushButton_search, &QPushButton::clicked, this, &PlayerCredits::search);
    connect(ui->addCredit, &QPushButton::clicked, this, &PlayerCredits::openCreatRecotd);
    connect(ui->refreshData, &QPushButton::clicked, this, &PlayerCredits::prepReloadModels);
    connect(ui->clearSearch, &QPushButton::clicked, this, &PlayerCredits::clearSearchText);
    connect(ui->addFilter, &QPushButton::clicked, this, &PlayerCredits::addFilter);
    connect(ui->clearFilter, &QPushButton::clicked, this, &PlayerCredits::clearFilter);

    connect(ui->currentPage, &QLineEdit::textChanged, this, &PlayerCredits::goToPage);
    connect(ui->searchText, &QLineEdit::textChanged, this, &PlayerCredits::search);

    connect(ui->checkBox, &QCheckBox::stateChanged, this, &PlayerCredits::selectTypeSearch);
    connect(ui->sorting, &QCheckBox::stateChanged, this, &PlayerCredits::sorting);

    connect(ui->radioButton_Sorting, &QRadioButton::toggled, this, &PlayerCredits::visibleSort);
    connect(ui->radioButton_Search, &QRadioButton::toggled, this, &PlayerCredits::visibleSearch);
    connect(ui->radioButton_Editing, &QRadioButton::toggled, this, &PlayerCredits::visibleEditing);
    connect(ui->radioButton_Filtr, &QRadioButton::toggled, this, &PlayerCredits::visibleFiltr);

    connect(ui->sortingColumn, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &PlayerCredits::sort);
    connect(ui->typeSorting, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &PlayerCredits::sort);

    connect(ui->tableView->horizontalHeader(), &QHeaderView::sectionClicked, this, &PlayerCredits::onHeaderClicked);
}

void PlayerCredits::updateCurrentPageInLabel(const int currentPage)
{
    blockAndOperate(ui->currentPage, [&]() {ui->currentPage->setText(QString::number(currentPage));});
}

void PlayerCredits::goToPage()
{
    if(ui->currentPage->text() == "0")
    {
        blockAndOperate(ui->currentPage, [&]() {ui->currentPage->clear();});
        return;
    }

    goToPageTimer.start(1000);
}

void PlayerCredits::search()
{
    pagination->search(ui->searchText->text(), typeSearch);
}

void PlayerCredits::onHeaderClicked(const int logicalIndex)
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

void PlayerCredits::prepReloadModels()
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

    pagination->reloadModels();
}

void PlayerCredits::openCreatRecotd()
{

}

void PlayerCredits::openEditRecotd()
{

}

void PlayerCredits::deleting()
{
    QString table = "Credits";
    QString idColumn = "ID_Credit";
    int id = getValueFromSelectedRow(ui->tableView, 1).toInt();

    deleteRecord(table, idColumn, id);
}

void PlayerCredits::clearSearchText()
{
    ui->searchText->clear();
}

void PlayerCredits::visibleSort(const bool flag)
{
    ui->label_3->setVisible(flag);
    ui->label_2->setVisible(flag);
    ui->sortingColumn->setVisible(flag);
    ui->typeSorting->setVisible(flag);
    ui->sorting->setVisible(flag);
}

void PlayerCredits::visibleSearch(const bool flag)
{
    ui->label->setVisible(flag);
    ui->searchColumn->setVisible(flag);
    ui->searchText->setVisible(flag);
    ui->checkBox->setVisible(flag);
    ui->pushButton_search->setVisible(flag);
    ui->clearSearch->setVisible(flag);
}

void PlayerCredits::visibleEditing(const bool flag)
{
    ui->addCredit->setVisible(flag);
}

void PlayerCredits::visibleFiltr(const bool flag)
{
    ui->addFilter->setVisible(flag);
    ui->clearFilter->setVisible(flag);
}

void PlayerCredits::addFilter()
{
    if (filter->exec() == QDialog::Accepted)
    {

    }
}

void PlayerCredits::runSearch()
{
    pagination->search(ui->searchText->text(), typeSearch);
}

void PlayerCredits::runGoToPage()
{
    pagination->goToPage(ui->currentPage->text());
}
