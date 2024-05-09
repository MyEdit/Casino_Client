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
}

void Credits::connects()
{
    connect(ui->prevButton, &QPushButton::clicked, pagination.get(), &Pagination::prev);
    connect(ui->nextButton, &QPushButton::clicked, pagination.get(), &Pagination::next);
    connect(ui->pushButton_search, &QPushButton::clicked, this, &Credits::search);
    connect(ui->addCredit, &QPushButton::clicked, this, &Credits::openCreatRecotd);
    connect(ui->editCredit, &QPushButton::clicked, this, &Credits::openEditRecotd);
    connect(ui->deleteCredit, &QPushButton::clicked, this, &Credits::deleting);
    connect(ui->refreshData, &QPushButton::clicked, this, &Credits::prepReloadModels);
    connect(ui->clearSearch, &QPushButton::clicked, this, &Credits::clearSearchText);

    connect(ui->pageNumberToNavigate, &QLineEdit::textChanged, this, &Credits::goToPage);
    connect(ui->searchText, &QLineEdit::textChanged, this, &Credits::search);

    connect(ui->checkBox_Sorting, &QCheckBox::stateChanged, this, &Credits::setVisibleSort);
    connect(ui->checkBox_Search, &QCheckBox::stateChanged, this, &Credits::setVisibleSearch);
    connect(ui->checkBox_Editing, &QCheckBox::stateChanged, this, &Credits::setVisibleEditing);

    connect(ui->checkBox, &QCheckBox::stateChanged, this, &Credits::selectTypeSearch);
    connect(ui->sorting, &QCheckBox::stateChanged, this, &Credits::sorting);

    connect(ui->sortingColumn, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &Credits::sort);
    connect(ui->typeSorting, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &Credits::sort);

    connect(ui->tableView->horizontalHeader(), &QHeaderView::sectionClicked, this, &Credits::onHeaderClicked);

    connect(pagination.get(), &Pagination::updateCurrentPageInLabel, this, &Credits::updateCurrentPageInLabel);
    connect(pagination.get(), &Pagination::setMaxPageInLabel, this, &Credits::setValueToMaxPage);
    connect(pagination.get(), &Pagination::blockInterface, this, &Credits::blockingInterface);

    connect(workingIsTableView.get(), &WorkingIsTableView::unlockInterface, this, &Credits::blockingInterface);

    connect(&goToPageTimer, &QTimer::timeout, this, [=]()
    {
        pagination->goToPage(ui->pageNumberToNavigate->text());
    });

    connect(&searchTimer, &QTimer::timeout, this, [=]()
    {
        pagination->search(ui->searchText->text(), typeSearch);
    });
}

void Credits::updateCurrentPageInLabel(const int currentPage)
{
    ui->labelCurrentPage->setText(QString::number(currentPage));
}

void Credits::goToPage()
{
    if(ui->pageNumberToNavigate->text() == "0")
    {
        blockAndOperate(ui->pageNumberToNavigate, [&]() {ui->pageNumberToNavigate->clear();});
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
    ui->labelCurrentPage->setText("0");

    ui->pageNumberToNavigate->clear();

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

void Credits::visibleSort(bool flag)
{
    ui->label_3->setVisible(flag);
    ui->label_2->setVisible(flag);
    ui->sortingColumn->setVisible(flag);
    ui->typeSorting->setVisible(flag);
    ui->sorting->setVisible(flag);
}

void Credits::visibleSearch(bool flag)
{
    ui->label->setVisible(flag);
    ui->searchColumn->setVisible(flag);
    ui->searchText->setVisible(flag);
    ui->checkBox->setVisible(flag);
    ui->pushButton_search->setVisible(flag);
    ui->clearSearch->setVisible(flag);
}

void Credits::visibleEditing(bool flag)
{
    ui->addCredit->setVisible(flag);
    ui->editCredit->setVisible(flag);
    ui->deleteCredit->setVisible(flag);
}

void Credits::visibleFiltr(bool flag)
{
    Q_UNUSED(flag);
}

void Credits::addFilter()
{

}

void Credits::clearFilter()
{

}
