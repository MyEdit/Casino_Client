#include "pagination.h"
#include <QDebug>

Pagination::Pagination(QWidget* parent, QTableView* table, QComboBox* column, QSharedPointer<WorkingIsTableView> workingIsTableView, ModelTypes modelTypes, QPushButton* prevButton, QPushButton* nextButton) :
    QWidget(parent),
    tableView(table),
    workingIsTableView(workingIsTableView),
    modelTypes(modelTypes),
    column(column),
    prevButton(prevButton),
    nextButton(nextButton)
{
    creatingObjects();
    assigningValues();
    connects();
}

void Pagination::start()
{
    initializationModels();
    loadingMaxPage();
}

void Pagination::creatingObjects()
{
    for(int i = 0; i < 3; i++)
        models.push_back(QSharedPointer<QStandardItemModel>::create());

    searchModule = QSharedPointer<SearchModule>::create();
}

void Pagination::updateTablePage()
{
    currentPage = (currentPage > maxPage) ? maxPage : currentPage;

    int startIndex = (currentPageInModel() - 1) * rowsPerPage;
    int endIndex = startIndex + rowsPerPage;

    if(!tableView->model())
    {
        emit blockInterface(true);
        return;
    }

    int rowCountModel = tableView->model()->rowCount();
    for (int row = 0; row < rowCountModel; row++)
    {
        bool rowVisible = (row >= startIndex && row < endIndex);
        tableView->setRowHidden(row, !rowVisible);
    }

    emit updateCurrentPageInLabel(currentPage);
}

int Pagination::currentPageInModel()
{
    if(currentPage == 0)
        return 1;

    int pageModel = currentPage % maxPageModel;

    if(pageModel == 0)
        pageModel = maxPageModel;

    return pageModel;
}

void Pagination::setMaxPage(const QString& rowCount)
{
    maxPage = std::ceil(rowCount.toDouble() / rowsPerPage);
    emit setMaxPageInLabel(maxPage);
}

int Pagination::getMaxPage()
{
    return maxPage;
}

void Pagination::prev()
{
    if (currentPage > 1)
    {
        nextButton->setEnabled(true);
        handlePrevPage();
    }
    else
        prevButton->setEnabled(false);
}

void Pagination::handlePrevPage()
{
    if (currentPageInModel() == minPageModel)
    {
        if (goToPrev && models[2]->rowCount() != 0)
            goToPrevModel();
        else
            prevButton->setEnabled(false);
    }
    else
    {
        currentPage--;
        updateTablePage();
    }
}

void Pagination::next()
{
    if (currentPage < maxPage)
    {
        prevButton->setEnabled(true);
        handleNextPage();
    }
    else
    {
        Notification::showNotification(TypeMessage::Warning, "Данных больше нет!");
        nextButton->setEnabled(false);
    }
}

void Pagination::handleNextPage()
{
    if (currentPageInModel() == maxPageModel)
    {
        if (goToNext && models[1]->rowCount() != 0)
            goToNextModel();
        else
            nextButton->setEnabled(false);
    }
    else
    {
        currentPage++;
        updateTablePage();
    }
}

void Pagination::goToNextModel()
{
    currentPage++;

    workingIsTableView->setModel(models[1]);
    updateTablePage();

    std::rotate(models.begin(), models.begin() + 1, models.end());

    int nextOffset = (currentPage + maxPageModel - 1) * rowsPerPage;
    loadingModel(ModelLoadingType::Next, nextOffset);
    goToNext = false;
}

void Pagination::goToPrevModel()
{
    currentPage--;

    workingIsTableView->setModel(models[2]);
    updateTablePage();

    std::rotate(models.begin(), models.begin() + (models.size() - 1), models.end());

    int prevOffset = (currentPage - maxPageModel * 2) * rowsPerPage;
    loadingModel(ModelLoadingType::Prev, prevOffset);
    goToPrev = false;
}

void Pagination::acceptModel(QSharedPointer<ModelData> structModel)
{
    switch (structModel->modelLoadingType)
    {
    case ModelLoadingType::Next:
    {
        models[1] = QSharedPointer<QStandardItemModel>(structModel->model);
        goToNext = true;
        nextButton->setEnabled(true);
        break;
    }

    case ModelLoadingType::Central:
    {
        models[0] = QSharedPointer<QStandardItemModel>(structModel->model);
        workingIsTableView->setModel(models[0]);
        updateTablePage();
        break;
    }

    case ModelLoadingType::Prev:
    {
        models[2] = QSharedPointer<QStandardItemModel>(structModel->model);
        goToPrev = true;
        prevButton->setEnabled(true);
        break;
    }
    }

    if(!searchText.isEmpty())
        searchInModel();
}

void Pagination::loadingModel(const ModelLoadingType type, const int offset)
{
    PacketTypes packettype = PacketTypes::P_SendModel;
    NetworkClient::sendToServer(&packettype, sizeof(PacketTypes));
    NetworkClient::sendToServer(&type, sizeof(ModelLoadingType));
    NetworkClient::sendToServer(&modelTypes, sizeof(ModelTypes));
    NetworkClient::sendToServer(&offset, sizeof(int));
    NetworkClient::sendToServer(P_SendModel::getTableName(modelTypes));
    NetworkClient::sendToServer(querySort);
    NetworkClient::sendToServer(where);
}

void Pagination::initializationModels()
{
    goToNext = false;
    goToPrev = false;
    int setPages = currentPage - currentPageInModel();

    int centralOffset = setPages * rowsPerPage;
    int nextOffset = (setPages + maxPageModel) * rowsPerPage;
    int prevOffset = (setPages - maxPageModel) * rowsPerPage;

    emit blockInterface(false);

    loadingModel(ModelLoadingType::Central, centralOffset);
    loadingModel(ModelLoadingType::Next, nextOffset);
    loadingModel(ModelLoadingType::Prev, prevOffset);
}

void Pagination::setWhere(const QString& where)
{
    this->where = where;
}

QString Pagination::getWhere() const
{
    return where;
}

void Pagination::loadingMaxPage()
{
    PacketTypes packettype = PacketTypes::P_Query;
    QString query = "SELECT COUNT(*) FROM " + P_SendModel::getTableName(modelTypes) + " WHERE 1=1 " + where;

    QueryTypes queryTypes = QueryTypes::CountEntrites;

    NetworkClient::sendToServer(&packettype, sizeof(PacketTypes));
    NetworkClient::sendToServer(&queryTypes, sizeof(QueryTypes));
    NetworkClient::sendToServer(&modelTypes, sizeof(ModelTypes));
    NetworkClient::sendToServer(query);
}

void Pagination::assigningValues()
{
    currentPage = 1;
    rowsPerPage = 10;
    maxPageModel = 5;
    minPageModel = 1;
}

void Pagination::connects()
{
    connect(NetworkClient::packetHandler, &PacketHandler::signalSetQueryModel, this, &Pagination::distributor);
    connect(NetworkClient::packetHandler, &PacketHandler::signalResultSearch, this, &Pagination::resultSearchInDB);
    connect(searchModule.get(), &SearchModule::signalNothingWasFoundInModel, this, &Pagination::searchInDB);
    connect(searchModule.get(), &SearchModule::signalResulSearchInModel, this, &Pagination::dataFoundInModel);
}

void Pagination::goToPage(const QString& page)
{
    if(page.isEmpty())
        return;

    if(page == "0")
        return;

    int currentPage = page.toInt();
    int setPages = this->currentPage - currentPageInModel();

    this->currentPage = (currentPage > maxPage) ? maxPage : currentPage;

    if(setPages < this->currentPage && this->currentPage <= (setPages + maxPageModel))
        updateTablePage();
    else
        initializationModels();
}

void Pagination::search(const QString& searchText, const QString& typeSearch)
{
    if(searchText.isEmpty())
        return;

    this->searchText = searchText;
    this->typeSearch = typeSearch;

    searchInModel();
}

void Pagination::searchInModel()
{
    emit blockInterface(false);
    searchModule->searchInModels(models, searchText, typeSearch, column->currentIndex(), rowsPerPage);
}

void Pagination::dataFoundInModel(QSharedPointer<ResultSearchInModel> resultSearch)
{
    workingIsTableView->setModel(resultSearch->model);
    workingIsTableView->setCurrentIndex(resultSearch->index);
    currentPage = resultSearch->currentPage;

    searchText.clear();
    typeSearch.clear();
    updateTablePage();
}

void Pagination::resultSearchInDB(QPair<ModelTypes, QString> result)
{
    if(result.first != modelTypes)
        return;

    QString page = QString::number(std::ceil(result.second.toDouble() / rowsPerPage));
    goToPage(page);
}

void Pagination::searchInDB()
{
    emit blockInterface(true);
    SearchModule::searchInDB(modelTypes, P_SendModel::getTableName(modelTypes), column->currentText(), searchText + typeSearch, querySort, where);
}

void Pagination::distributor(QSharedPointer<QueryData> data)
{
    if(data->modelTypes != modelTypes)
        return;

    setMaxPage(data->result);
}

void Pagination::reloadModels()
{
    currentPage = 1;
    loadingMaxPage();
    initializationModels();
}

void Pagination::setSort(const QString& sort)
{
    querySort = sort;
}
