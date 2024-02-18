#include "existingtables.h"
#include "ui_existingtables.h"

ExistingTables::ExistingTables(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExistingTables)
{
    ui->setupUi(this);

    assigningValues();
    creatingObjects();
    connects();
    workingWithTableView();

    pagination->start();
}

ExistingTables::~ExistingTables()
{
    delete ui;
}

void ExistingTables::workingWithTableView()
{
    workingIsTableView->settingVisualTableView();
}

void ExistingTables::setModel(ModelData model)
{
    pagination->acceptModel(model);
}

void ExistingTables::setValueToMaxPage(int maxPage)
{
    ui->labelMaxPage->setText(QString::number(maxPage));
}

void ExistingTables::assigningValues()
{
    boxsNameColumn.push_back(ui->searchColumn);
    boxsNameColumn.push_back(ui->sortingColumn);

    modelTypes = ModelTypes::ActiveTables;

    typeSearch = '%';

    goToPageTimer.setSingleShot(true);
    searchTimer.setSingleShot(true);
}

void ExistingTables::creatingObjects()
{
    workingIsTableView = new WorkingIsTableView(ui->tableView, &boxsNameColumn);
    pagination = new Pagination(this, ui->tableView, ui->prevButton, ui->nextButton, workingIsTableView, modelTypes);
}

void ExistingTables::connects()
{
    connect(ui->prevButton, &QPushButton::clicked, pagination, &Pagination::prev);
    connect(ui->nextButton, &QPushButton::clicked, pagination, &Pagination::next);
    connect(ui->pageNumberToNavigate, &QLineEdit::textChanged, this, &ExistingTables::goToPage);
    connect(ui->searchText, &QLineEdit::textChanged, this, &ExistingTables::search);
    connect(ui->checkBox, &QCheckBox::stateChanged, this, &ExistingTables::selectTypeSearch);

    connect(pagination, &Pagination::updateCurrentPageInLabel, this, &ExistingTables::updateCurrentPageInLabel);
    connect(pagination, &Pagination::setMaxPageInLabel, this, &ExistingTables::setValueToMaxPage);
    connect(pagination, &Pagination::blockInterface, this, &ExistingTables::blockingInterface);

    connect(workingIsTableView, &WorkingIsTableView::unlockInterface, this, &ExistingTables::blockingInterface);

    connect(&goToPageTimer, &QTimer::timeout, this, [=]()
    {
        pagination->goToPage(ui->pageNumberToNavigate->text());
    });

    connect(&searchTimer, &QTimer::timeout, this, [=]()
    {
        pagination->search(ui->searchText->text(), typeSearch, ui->searchColumn);
    });
}

void ExistingTables::updateCurrentPageInLabel(int currentPage)
{
    ui->labelCurrentPage->setText(QString::number(currentPage));
}

void ExistingTables::blockAndOperate(QObject* widget, const std::function<void()>& operation)
{
    widget->blockSignals(true);
    operation();
    widget->blockSignals(false);
}

void ExistingTables::goToPage()
{
    if(ui->pageNumberToNavigate->text() == "0")
    {
        blockAndOperate(ui->pageNumberToNavigate, [&]() {ui->pageNumberToNavigate->clear();});
        return;
    }

    goToPageTimer.start(1000);
}

void ExistingTables::blockingInterface(bool flag)
{
    QList<QPushButton*> pushbuttons = this->findChildren<QPushButton*>();
    for(QPushButton* pushbutton : pushbuttons)
        pushbutton->setEnabled(flag);

    QList<QComboBox*> comboBoxs = this->findChildren<QComboBox*>();
    for(QComboBox* comboBox : comboBoxs)
        comboBox->setEnabled(flag);

    ui->sorting->setEnabled(flag);
    ui->pageNumberToNavigate->setEnabled(flag);
    ui->searchText->setEnabled(flag);
}

void ExistingTables::search()
{
    searchTimer.start(1000);
}

void ExistingTables::selectTypeSearch(int arg)
{
    if(arg == 2)
        typeSearch.clear();
    else if(arg == 0)
        typeSearch = '%';

    search();
}
