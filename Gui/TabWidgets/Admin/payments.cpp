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
    pagination = QSharedPointer<Pagination>(new Pagination(this, ui->tableView, ui->searchColumn, workingIsTableView, modelTypes));
}

void Payments::connects()
{
    connect(ui->prevButton, &QPushButton::clicked, pagination.get(), &Pagination::prev);
    connect(ui->nextButton, &QPushButton::clicked, pagination.get(), &Pagination::next);
    connect(ui->pushButton_search, &QPushButton::clicked, this, &Payments::search);
    connect(ui->addPayment, &QPushButton::clicked, this, &Payments::openCreatRecotd);
    connect(ui->editPayment, &QPushButton::clicked, this, &Payments::openEditRecotd);
    connect(ui->deletePayment, &QPushButton::clicked, this, &Payments::deleting);
    connect(ui->refreshData, &QPushButton::clicked, this, &Payments::prepReloadModels);
    connect(ui->clearSearch, &QPushButton::clicked, this, &Payments::clearSearchText);

    connect(ui->pageNumberToNavigate, &QLineEdit::textChanged, this, &Payments::goToPage);
    connect(ui->searchText, &QLineEdit::textChanged, this, &Payments::search);

    connect(ui->checkBox, &QCheckBox::stateChanged, this, &Payments::selectTypeSearch);
    connect(ui->sorting, &QCheckBox::stateChanged, this, &Payments::sorting);

    connect(ui->checkBox_Sorting, &QCheckBox::stateChanged, this, &Payments::setVisibleSort);
    connect(ui->checkBox_Search, &QCheckBox::stateChanged, this, &Payments::setVisibleSearch);
    connect(ui->checkBox_Editing, &QCheckBox::stateChanged, this, &Payments::setVisibleEditing);

    connect(ui->sortingColumn, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &Payments::sort);
    connect(ui->typeSorting, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &Payments::sort);

    connect(ui->tableView->horizontalHeader(), &QHeaderView::sectionClicked, this, &Payments::onHeaderClicked);

    connect(pagination.get(), &Pagination::updateCurrentPageInLabel, this, &Payments::updateCurrentPageInLabel);
    connect(pagination.get(), &Pagination::setMaxPageInLabel, this, &Payments::setValueToMaxPage);
    connect(pagination.get(), &Pagination::blockInterface, this, &Payments::blockingInterface);

    connect(workingIsTableView.get(), &WorkingIsTableView::unlockInterface, this, &Payments::blockingInterface);

    connect(&goToPageTimer, &QTimer::timeout, this, [=]()
    {
        pagination->goToPage(ui->pageNumberToNavigate->text());
    });

    connect(&searchTimer, &QTimer::timeout, this, [=]()
    {
        pagination->search(ui->searchText->text(), typeSearch);
    });
}

void Payments::updateCurrentPageInLabel(const int currentPage)
{
    ui->labelCurrentPage->setText(QString::number(currentPage));
}

void Payments::goToPage()
{
    if(ui->pageNumberToNavigate->text() == "0")
    {
        blockAndOperate(ui->pageNumberToNavigate, [&]() {ui->pageNumberToNavigate->clear();});
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
    ui->labelCurrentPage->setText("0");

    ui->pageNumberToNavigate->clear();

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

void Payments::visibleSort(bool flag)
{
    ui->label_3->setVisible(flag);
    ui->label_2->setVisible(flag);
    ui->sortingColumn->setVisible(flag);
    ui->typeSorting->setVisible(flag);
    ui->sorting->setVisible(flag);
}

void Payments::visibleSearch(bool flag)
{
    ui->label->setVisible(flag);
    ui->searchColumn->setVisible(flag);
    ui->searchText->setVisible(flag);
    ui->checkBox->setVisible(flag);
    ui->pushButton_search->setVisible(flag);
    ui->clearSearch->setVisible(flag);
}

void Payments::visibleEditing(bool flag)
{
    ui->addPayment->setVisible(flag);
    ui->editPayment->setVisible(flag);
    ui->deletePayment->setVisible(flag);
}

