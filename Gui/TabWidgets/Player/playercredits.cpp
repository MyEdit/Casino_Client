#include "playercredits.h"
#include "ui_playercredits.h"

PlayerCredits::PlayerCredits(QWidget *parent) :
    BaseClassSearchWindow(parent),
    ui(new Ui::PlayerCredits)
{
    ui->setupUi(this);

    baseSetting();

    where = "and ID_User = '" + QString::number(P_Authorization::getPlayer()->getID()) + "'";
    pagination->setWhere(where);
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
}

void PlayerCredits::connects()
{
    connect(ui->prevButton, &QPushButton::clicked, pagination.get(), &Pagination::prev);
    connect(ui->nextButton, &QPushButton::clicked, pagination.get(), &Pagination::next);
    connect(ui->pushButton_search, &QPushButton::clicked, this, &PlayerCredits::search);
    connect(ui->addCredit, &QPushButton::clicked, this, &PlayerCredits::openCreatRecotd);
    connect(ui->refreshData, &QPushButton::clicked, this, &PlayerCredits::prepReloadModels);
    connect(ui->clearSearch, &QPushButton::clicked, this, &PlayerCredits::clearSearchText);

    connect(ui->pageNumberToNavigate, &QLineEdit::textChanged, this, &PlayerCredits::goToPage);
    connect(ui->searchText, &QLineEdit::textChanged, this, &PlayerCredits::search);

    connect(ui->checkBox, &QCheckBox::stateChanged, this, &PlayerCredits::selectTypeSearch);
    connect(ui->sorting, &QCheckBox::stateChanged, this, &PlayerCredits::sorting);

    connect(ui->checkBox_Sorting, &QCheckBox::stateChanged, this, &PlayerCredits::setVisibleSort);
    connect(ui->checkBox_Search, &QCheckBox::stateChanged, this, &PlayerCredits::setVisibleSearch);

    connect(ui->sortingColumn, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &PlayerCredits::sort);
    connect(ui->typeSorting, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &PlayerCredits::sort);

    connect(ui->tableView->horizontalHeader(), &QHeaderView::sectionClicked, this, &PlayerCredits::onHeaderClicked);

    connect(pagination.get(), &Pagination::updateCurrentPageInLabel, this, &PlayerCredits::updateCurrentPageInLabel);
    connect(pagination.get(), &Pagination::setMaxPageInLabel, this, &PlayerCredits::setValueToMaxPage);
    connect(pagination.get(), &Pagination::blockInterface, this, &PlayerCredits::blockingInterface);

    connect(workingIsTableView.get(), &WorkingIsTableView::unlockInterface, this, &PlayerCredits::blockingInterface);

    connect(&goToPageTimer, &QTimer::timeout, this, [=]()
    {
        pagination->goToPage(ui->pageNumberToNavigate->text());
    });

    connect(&searchTimer, &QTimer::timeout, this, [=]()
    {
        pagination->search(ui->searchText->text(), typeSearch);
    });
}

void PlayerCredits::updateCurrentPageInLabel(const int currentPage)
{
    ui->labelCurrentPage->setText(QString::number(currentPage));
}

void PlayerCredits::goToPage()
{
    if(ui->pageNumberToNavigate->text() == "0")
    {
        blockAndOperate(ui->pageNumberToNavigate, [&]() {ui->pageNumberToNavigate->clear();});
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
    }
    else
        pagination->setSort("");

    ui->labelMaxPage->setText("????");
    ui->labelCurrentPage->setText("0");

    ui->pageNumberToNavigate->clear();

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

void PlayerCredits::visibleSort(bool flag)
{
    ui->label_3->setVisible(flag);
    ui->label_2->setVisible(flag);
    ui->sortingColumn->setVisible(flag);
    ui->typeSorting->setVisible(flag);
    ui->sorting->setVisible(flag);
}

void PlayerCredits::visibleSearch(bool flag)
{
    ui->label->setVisible(flag);
    ui->searchColumn->setVisible(flag);
    ui->searchText->setVisible(flag);
    ui->checkBox->setVisible(flag);
    ui->pushButton_search->setVisible(flag);
    ui->clearSearch->setVisible(flag);
}
