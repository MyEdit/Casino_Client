#include "playerpayments.h"
#include "ui_playerpayments.h"

PlayerPayments::PlayerPayments(QWidget *parent) :
    BaseClassSearchWindow(parent),
    ui(new Ui::PlayerPayments)
{
    ui->setupUi(this);

    baseSetting();

    defaultFilter = "and ID_User = '" + QString::number(P_Authorization::getPlayer()->getID()) + "'";
    pagination->setWhere(defaultFilter);
}

PlayerPayments::~PlayerPayments()
{
    delete ui;
}

void PlayerPayments::prepReloadModels()
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

void PlayerPayments::setValueToMaxPage(const int maxPage)
{
    ui->labelMaxPage->setText(QString::number(maxPage));
}

void PlayerPayments::assigningValues()
{
    BaseClassSearchWindow::assigningValues();

    boxsNameColumn.push_back(ui->searchColumn);
    boxsNameColumn.push_back(ui->sortingColumn);

    modelTypes = ModelTypes::Payments;
}

void PlayerPayments::updateCurrentPageInLabel(const int currentPage)
{
    blockAndOperate(ui->currentPage, [&]() {ui->currentPage->setText(QString::number(currentPage));});
}

void PlayerPayments::creatingObjects()
{
    workingIsTableView = QSharedPointer<WorkingIsTableView>(new WorkingIsTableView(ui->tableView, &boxsNameColumn));
    pagination = QSharedPointer<Pagination>(new Pagination(this, ui->tableView, ui->searchColumn, workingIsTableView, modelTypes));
    filter = QSharedPointer<F_PlayerPayment>(new F_PlayerPayment());
}

void PlayerPayments::goToPage()
{
    if(ui->currentPage->text() == "0")
    {
        blockAndOperate(ui->currentPage, [&]() {ui->currentPage->clear();});
        return;
    }

    goToPageTimer.start(1000);
}

void PlayerPayments::connects()
{
    BaseClassSearchWindow::connects();

    connect(ui->prevButton, &QPushButton::clicked, pagination.get(), &Pagination::prev);
    connect(ui->nextButton, &QPushButton::clicked, pagination.get(), &Pagination::next);
    connect(ui->pushButton_search, &QPushButton::clicked, this, &PlayerPayments::search);
    connect(ui->refreshData, &QPushButton::clicked, this, &PlayerPayments::prepReloadModels);
    connect(ui->clearSearch, &QPushButton::clicked, this, &PlayerPayments::clearSearchText);
    connect(ui->addFilter, &QPushButton::clicked, this, &PlayerPayments::addFilter);
    connect(ui->clearFilter, &QPushButton::clicked, this, &PlayerPayments::clearFilter);

    connect(ui->currentPage, &QLineEdit::textChanged, this, &PlayerPayments::goToPage);
    connect(ui->searchText, &QLineEdit::textChanged, this, &PlayerPayments::search);

    connect(ui->checkBox, &QCheckBox::stateChanged, this, &PlayerPayments::selectTypeSearch);
    connect(ui->sorting, &QCheckBox::stateChanged, this, &PlayerPayments::sorting);

    connect(ui->radioButton_Sorting, &QRadioButton::toggled, this, &PlayerPayments::visibleSort);
    connect(ui->radioButton_Search, &QRadioButton::toggled, this, &PlayerPayments::visibleSearch);
    connect(ui->radioButton_Filtr, &QRadioButton::toggled, this, &PlayerPayments::visibleFiltr);

    connect(ui->checkBox, &QCheckBox::stateChanged, this, &PlayerPayments::selectTypeSearch);

    connect(ui->tableView->horizontalHeader(), &QHeaderView::sectionClicked, this, &PlayerPayments::onHeaderClicked);
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

void PlayerPayments::visibleSort(const bool flag)
{
    ui->label_19->setVisible(flag);
    ui->label_20->setVisible(flag);
    ui->sortingColumn->setVisible(flag);
    ui->typeSorting->setVisible(flag);
    ui->sorting->setVisible(flag);
}

void PlayerPayments::visibleSearch(const bool flag)
{
    ui->label->setVisible(flag);
    ui->searchColumn->setVisible(flag);
    ui->searchText->setVisible(flag);
    ui->checkBox->setVisible(flag);
    ui->pushButton_search->setVisible(flag);
    ui->clearSearch->setVisible(flag);
}

void PlayerPayments::visibleEditing(const bool flag)
{
    Q_UNUSED(flag);
}

void PlayerPayments::visibleFiltr(const bool flag)
{
    ui->addFilter->setVisible(flag);
    ui->clearFilter->setVisible(flag);
}

void PlayerPayments::addFilter()
{
    if (filter->exec() == QDialog::Accepted)
    {

    }
}

void PlayerPayments::runSearch()
{
    pagination->search(ui->searchText->text(), typeSearch);
}

void PlayerPayments::runGoToPage()
{
    pagination->goToPage(ui->currentPage->text());
}
