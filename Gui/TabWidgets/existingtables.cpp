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

    goToPageTimer.setSingleShot(true);
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

    connect(pagination, &Pagination::updateCurrentPageInLabel, this, &ExistingTables::updateCurrentPageInLabel);
    connect(pagination, &Pagination::setMaxPageInLabel, this, &ExistingTables::setValueToMaxPage);
    connect(pagination, &Pagination::blockInterface, this, &ExistingTables::blockingInterface);

    connect(workingIsTableView, &WorkingIsTableView::unlockInterface, this, &ExistingTables::blockingInterface);

    connect(&goToPageTimer, &QTimer::timeout, this, [=]()
    {
        if(!ui->pageNumberToNavigate->text().isEmpty())
        {
//            _like.clear();
            pagination->goToPage(ui->pageNumberToNavigate->text().toInt());
        }
    });
}

void ExistingTables::updateCurrentPageInLabel(int currentPage)
{
    ui->labelCurrentPage->setText(QString::number(currentPage));
}

void ExistingTables::goToPage()
{
    if(ui->pageNumberToNavigate->text() == "0")
        ui->pageNumberToNavigate->clear();

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

    qDebug() << flag;

    ui->sorting->setEnabled(flag);
    ui->pageNumberToNavigate->setEnabled(flag);
    ui->searchText->setEnabled(flag);
}

