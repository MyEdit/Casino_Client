#include "playerpayments.h"
#include "ui_playerpayments.h"

PlayerPayments::PlayerPayments(QWidget *parent) :
    BaseClassSearchWindow(parent),
    ui(new Ui::PlayerPayments)
{
    ui->setupUi(this);

    baseSetting();

    where = "and ID_User = '" + QString::number(P_Authorization::getPlayer()->getID()) + "'";
    pagination->setWhere(where);
}

PlayerPayments::~PlayerPayments()
{
    delete ui;
}

void PlayerPayments::prepReloadModels()
{
    QString typeSort = typesSorting[0];
    pagination->setSort("ORDER BY [Date] " + typeSort);

    ui->labelMaxPage->setText("????");
    ui->labelCurrentPage->setText("0");

    ui->pageNumberToNavigate->clear();

    pagination->reloadModels();
}

void PlayerPayments::setValueToMaxPage(const int maxPage)
{
    ui->labelMaxPage->setText(QString::number(maxPage));
}

void PlayerPayments::assigningValues()
{
    BaseClassSearchWindow::assigningValues();

    boxsNameColumn.push_back(ui->searchColumn);

    modelTypes = ModelTypes::Payments;
}

void PlayerPayments::updateCurrentPageInLabel(const int currentPage)
{
    ui->labelCurrentPage->setText(QString::number(currentPage));
}

void PlayerPayments::creatingObjects()
{
    workingIsTableView = QSharedPointer<WorkingIsTableView>(new WorkingIsTableView(ui->tableView, &boxsNameColumn));
    pagination = QSharedPointer<Pagination>(new Pagination(this, ui->tableView, ui->searchColumn, workingIsTableView, modelTypes));
}

void PlayerPayments::goToPage()
{
    if(ui->pageNumberToNavigate->text() == "0")
    {
        blockAndOperate(ui->pageNumberToNavigate, [&]() {ui->pageNumberToNavigate->clear();});
        return;
    }

    goToPageTimer.start(1000);
}

void PlayerPayments::connects()
{
    connect(ui->prevButton, &QPushButton::clicked, pagination.get(), &Pagination::prev);
    connect(ui->nextButton, &QPushButton::clicked, pagination.get(), &Pagination::next);
    connect(ui->pushButton_search, &QPushButton::clicked, this, &PlayerPayments::search);
    connect(ui->refreshData, &QPushButton::clicked, this, &PlayerPayments::prepReloadModels);
    connect(ui->clearSearch, &QPushButton::clicked, this, &PlayerPayments::clearSearchText);

    connect(ui->pageNumberToNavigate, &QLineEdit::textChanged, this, &PlayerPayments::goToPage);
    connect(ui->searchText, &QLineEdit::textChanged, this, &PlayerPayments::search);

    connect(ui->checkBox, &QCheckBox::stateChanged, this, &PlayerPayments::selectTypeSearch);
    connect(ui->sorting, &QCheckBox::stateChanged, this, &PlayerPayments::sorting);

    connect(ui->checkBox_Sorting, &QCheckBox::stateChanged, this, &PlayerPayments::setVisibleSort);
    connect(ui->checkBox_Search, &QCheckBox::stateChanged, this, &PlayerPayments::setVisibleSearch);

    connect(ui->checkBox, &QCheckBox::stateChanged, this, &PlayerPayments::selectTypeSearch);

    connect(ui->tableView->horizontalHeader(), &QHeaderView::sectionClicked, this, &PlayerPayments::onHeaderClicked);

    connect(pagination.get(), &Pagination::updateCurrentPageInLabel, this, &PlayerPayments::updateCurrentPageInLabel);
    connect(pagination.get(), &Pagination::setMaxPageInLabel, this, &PlayerPayments::setValueToMaxPage);
    connect(pagination.get(), &Pagination::blockInterface, this, &PlayerPayments::blockingInterface);

    connect(workingIsTableView.get(), &WorkingIsTableView::unlockInterface, this, &PlayerPayments::blockingInterface);

    connect(&goToPageTimer, &QTimer::timeout, this, [=]()
    {
        pagination->goToPage(ui->pageNumberToNavigate->text());
    });

    connect(&searchTimer, &QTimer::timeout, this, [=]()
    {
        pagination->search(ui->searchText->text(), typeSearch);
    });
}

void PlayerPayments::search()
{
    searchTimer.start(500);
}

void PlayerPayments::onHeaderClicked(const int logicalIndex)
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

void PlayerPayments::openCreatRecotd()
{

}

void PlayerPayments::openEditRecotd()
{

}

void PlayerPayments::deleting()
{

}

void PlayerPayments::clearSearchText()
{
    ui->searchText->clear();
}

void PlayerPayments::visibleSort(bool flag)
{
    ui->label_19->setVisible(flag);
    ui->label_20->setVisible(flag);
    ui->sortingColumn->setVisible(flag);
    ui->typeSorting->setVisible(flag);
    ui->sorting->setVisible(flag);
}

void PlayerPayments::visibleSearch(bool flag)
{
    ui->label->setVisible(flag);
    ui->searchColumn->setVisible(flag);
    ui->searchText->setVisible(flag);
    ui->checkBox->setVisible(flag);
    ui->pushButton_search->setVisible(flag);
    ui->clearSearch->setVisible(flag);
}

void PlayerPayments::visibleEditing(bool flag)
{
    Q_UNUSED(flag);
}
