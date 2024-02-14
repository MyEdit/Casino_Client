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
    getMaxPage();
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

void ExistingTables::setValueToMaxPage(QString rowCount)
{
    pagination->setMaxPage(rowCount);
    ui->labelMaxPage->setText(QString::number(pagination->getMaxPage()));
}

void ExistingTables::assigningValues()
{
    _currentPage = 1;
    _rowsPerPage = 10;
    _typeSearch = "%";

    _sortingOn = false;

    _typesSorting =
    {
        {0, "ASC"},
        {1, "DESC"}
    };

    _searchTimer.setSingleShot(true);
    _goToPageTimer.setSingleShot(true);
    _resizeTimer.setSingleShot(true);

    boxsNameColumn.push_back(ui->searchColumn);
    boxsNameColumn.push_back(ui->sortingColumn);
}

void ExistingTables::creatingObjects()
{
    for(int i = 0; i < 3; i++)
        _models.push_back(QSharedPointer<QStandardItemModel>::create());

    workingIsTableView = new WorkingIsTableView(ui->tableView, &boxsNameColumn);
    pagination = new Pagination(this, ui->tableView, ui->prevButton, ui->nextButton, workingIsTableView);
}

void ExistingTables::connects()
{
    connect(NetworkClient::packetHandler, &PacketHandler::signalSetQueryModel, this, &ExistingTables::setValueToMaxPage);
    connect(&_searchTimer, &QTimer::timeout, this, &ExistingTables::searchInModels);
    connect(ui->prevButton, &QPushButton::clicked, pagination, &Pagination::prev);
    connect(ui->nextButton, &QPushButton::clicked, pagination, &Pagination::next);
    connect(pagination, &Pagination::updateCurrentPageInLabel, this, &ExistingTables::updateCurrentPageInLabel);
}

void ExistingTables::updateTablePage()
{
    pagination->updateTablePage();
}

void ExistingTables::updateCurrentPageInLabel(int currentPage)
{
    ui->labelCurrentPage->setText(QString::number(currentPage));
}

//Надо перенести в класс поиска
void ExistingTables::searchInModels()
{
//    if(ui->searchText->text().isEmpty())
//        return;

//    bool resultSearchInModel = false;
//    _like = ui->searchText->text();
//    _column = ui->searchColumn->currentText();

//    for (QSharedPointer<QStandardItemModel> model : _models)
//    {
//        for (int row = 0; row < model->rowCount(); row++)
//        {
//            QModelIndex index = model->index(row, ui->searchColumn->currentIndex() + 1);
//            QVariant data = model->data(index);

//            if (_typeSearch == "%")
//                resultSearchInModel = data.toString().startsWith(_like, Qt::CaseInsensitive);
//            else
//                resultSearchInModel = (data.toString().compare(_like, Qt::CaseInsensitive) == 0);

//            if (resultSearchInModel)
//            {
//                double resultRow = model->data(model->index(row, 0)).toDouble();
//                _currentPage = std::ceil(resultRow / _rowsPerPage);
//                setModel(model.data());
//                ui->tableView->setCurrentIndex(index);
//                return;
//            }
//        }
//    }

//    searchInDB();
}

void ExistingTables::getMaxPage()
{
    PacketTypes packettype = PacketTypes::P_QueryWithoutResponce;
    QueryTypes queryTypes = QueryTypes::CountEntrites;
    ModelTypes modelTypes = ModelTypes::ExistingTables;

    NetworkClient::sendToServer(&packettype, sizeof(PacketTypes));
    NetworkClient::sendToServer(&queryTypes, sizeof(QueryTypes));
    NetworkClient::sendToServer(&modelTypes, sizeof(ModelTypes));
}

void ExistingTables::on_searchText_textChanged(const QString &arg1)
{
    Q_UNUSED(arg1);
    _searchTimer.start(1000);
}
