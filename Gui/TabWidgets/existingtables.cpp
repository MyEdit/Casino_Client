#include "existingtables.h"
#include "ui_existingtables.h"

ExistingTables::ExistingTables(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExistingTables)
{
    ui->setupUi(this);

    workingWithTableView();
    assigningValues();
    creatingObjects();
    connects();
    getMaxPage();
}

ExistingTables::~ExistingTables()
{
    delete ui;
}

//По хорошему эту и всё что относиться к визуалу перенести в отдельный класс
void ExistingTables::workingWithTableView()
{
    ui->tableView->setStyleSheet("selection-background-color: rgb(42, 117, 255);");
    ui->tableView->setWordWrap(false);

    //Устанавливка жирного шрифта для заголовков столбцов
    QFont font = ui->tableView->horizontalHeader()->font();
    font.setBold(true);
    ui->tableView->horizontalHeader()->setFont(font);

    //Скрыть номер строк в tableView
    ui->tableView->verticalHeader()->setVisible(false);

    ui->tableView->horizontalHeader()->setStyleSheet("QHeaderView { font-size: 14pt; }");

    //Устанавка растягивания для заголовков строк и столбцов на по размеру содержимого
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //Устанавка растягивания для строк и столбцов на всю высоту
    ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //Запрет редактирования данных в ячейке
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //Для выделения всей строки
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
}

void ExistingTables::setModel(QStandardItemModel* model)
{  
    if(model->rowCount() == 0)
    {
        Message::logWarn("Данных нет");
        return;
    }

    ui->tableView->setModel(model);

    ui->tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);

    for (int col = 1; col < model->columnCount(); ++col)
    {
        QString originalHeaderText = model->headerData(col, Qt::Horizontal).toString();
        QString wrappedHeaderText = originalHeaderText.replace(" ", "\n");
        model->setHeaderData(col, Qt::Horizontal, wrappedHeaderText);
    }

    if(_headers.isEmpty())
        setValueNameColumn();
}

void ExistingTables::setValueNameColumn()
{
    _headers = getColumnHeaders();
    for(QString nameColumn : _headers)
    {
        ui->sortingColumn->blockSignals(true);
        ui->sortingColumn->addItem(nameColumn);
        ui->sortingColumn->blockSignals(false);

        ui->searchColumn->blockSignals(true);
        ui->searchColumn->addItem(nameColumn);
        ui->searchColumn->blockSignals(false);
    }
}

QVector<QString> ExistingTables::getColumnHeaders()
{
    QVector<QString> headers;
    QAbstractItemModel* model = ui->tableView->model();
    int columnCount = model->columnCount();

    for (int column = 0; column < columnCount; ++column)
    {
        QString header = model->headerData(column, Qt::Horizontal).toString();
        header = header.replace("\n", " ");
        headers.push_back(header);
    }

    return headers;
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
}

void ExistingTables::creatingObjects()
{
    for(int i = 0; i < 3; i++)
        _models.push_back(QSharedPointer<QStandardItemModel>::create());

    pagination = new Pagination(this, ui->tableView, ui->prevButton, ui->nextButton);
}

void ExistingTables::connects()
{
    connect(NetworkClient::packetHandler, &PacketHandler::signalSetQueryModel, this, &ExistingTables::setValueToMaxPage);
    connect(&_searchTimer, &QTimer::timeout, this, &ExistingTables::searchInModels);
    connect(ui->prevButton, &QPushButton::clicked, pagination, &Pagination::prev);
    connect(ui->nextButton, &QPushButton::clicked, pagination, &Pagination::next);
}

void ExistingTables::updateTablePage()
{
    updateCurrentPageInLabel();

    pagination->updateTablePage();
}

void ExistingTables::updateCurrentPageInLabel()
{
    ui->labelCurrentPage->setText(QString::number(_currentPage));
}

//Надо перенести в класс поиска
void ExistingTables::searchInModels()
{
    if(ui->searchText->text().isEmpty())
        return;

    bool resultSearchInModel = false;
    _like = ui->searchText->text();
    _column = ui->searchColumn->currentText();

    for (QSharedPointer<QStandardItemModel> model : _models)
    {
        for (int row = 0; row < model->rowCount(); row++)
        {
            QModelIndex index = model->index(row, ui->searchColumn->currentIndex() + 1);
            QVariant data = model->data(index);

            if (_typeSearch == "%")
                resultSearchInModel = data.toString().startsWith(_like, Qt::CaseInsensitive);
            else
                resultSearchInModel = (data.toString().compare(_like, Qt::CaseInsensitive) == 0);

            if (resultSearchInModel)
            {
                double resultRow = model->data(model->index(row, 0)).toDouble();
                _currentPage = std::ceil(resultRow / _rowsPerPage);
                setModel(model.data());
                ui->tableView->setCurrentIndex(index);
                return;
            }
        }
    }

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
