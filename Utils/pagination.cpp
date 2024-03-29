﻿#include "pagination.h"
#include <QDebug>

Pagination::Pagination(QWidget* parent, QTableView* table, QPushButton* prevButton, QPushButton* nextButton, QSharedPointer<WorkingIsTableView> workingIsTableView, ModelTypes modelTypes) :
    QWidget(parent),
    tableView(table),
    prevButton(prevButton),
    nextButton(nextButton),
    workingIsTableView(workingIsTableView),
    modelTypes(modelTypes)
{
    creatingObjects();
    assigningValues();
    connects();
}

void Pagination::start()
{
    loadingMaxPage();
    initializationModels();
}

void Pagination::creatingObjects()
{
    for(int i = 0; i < 3; i++)
        models.push_back(QSharedPointer<QStandardItemModel>::create());

    searchModule = QSharedPointer<SearchModule>::create(workingIsTableView);
}

void Pagination::updateTablePage()
{
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
    int pageModel = currentPage % maxPageModel;

    if(pageModel == 0)
        pageModel = maxPageModel;

    return pageModel;
}

void Pagination::setMaxPage(QString rowCount)
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
    if(currentPage > 1)
    {
        nextButton->setEnabled(true);
        if(currentPageInModel() == minPageModel)
        {
            if(models[2]->rowCount() != 0)
                goToPrevModel();
        }
        else
        {
            currentPage--;
            updateTablePage();
        }
    }
}

void Pagination::next()
{
    if(currentPage < maxPage)
    {
        prevButton->setEnabled(true);
        if(currentPageInModel() == maxPageModel)
        {
            if(models[1]->rowCount() != 0)
                goToNextModel();
        }
        else
        {
            currentPage++;
            updateTablePage();
        }
    }
    else
        QMessageBox::warning(this, "Внимание", "Данных больше нет!", QMessageBox::Ok);
}

void Pagination::acceptModel(ModelData structModel)
{
    switch (structModel.modelLoadingType)
    {
    case ModelLoadingType::Next:
        models[1] = QSharedPointer<QStandardItemModel>(structModel.model);
        break;

    case ModelLoadingType::Central:
        models[0] = QSharedPointer<QStandardItemModel>(structModel.model);
        workingIsTableView->setModel(models[0]);
        updateTablePage();
        break;

    case ModelLoadingType::Prev:
        models[2] = QSharedPointer<QStandardItemModel>(structModel.model);
        break;
    }

    if(!searchText.isEmpty())
        searchInModel();
}

void Pagination::goToNextModel()
{
    currentPage++;

    workingIsTableView->setModel(models[1]);
    std::rotate(models.begin(), models.begin() + 1, models.end());

    int nextOffset = (currentPage + maxPageModel - 1) * rowsPerPage;
    loadingModel(ModelLoadingType::Next, nextOffset);
    updateTablePage();
}

void Pagination::goToPrevModel()
{
    currentPage--;

    workingIsTableView->setModel(models[2]);
    std::rotate(models.begin(), models.begin() + (models.size() - 1), models.end());

    int prevOffset = (currentPage - maxPageModel * 2) * rowsPerPage;
    loadingModel(ModelLoadingType::Prev, prevOffset);

    updateTablePage();
}

void Pagination::loadingModel(ModelLoadingType type, int offset)
{
    PacketTypes packettype = PacketTypes::P_SendModel;
    NetworkClient::sendToServer(&packettype, sizeof(PacketTypes));
    NetworkClient::sendToServer(&type, sizeof(ModelLoadingType));
    NetworkClient::sendToServer(&modelTypes, sizeof(ModelTypes));
    NetworkClient::sendToServer(&offset, sizeof(int));
    NetworkClient::sendToServer(P_SendModel::tableNames[modelTypes]);
    NetworkClient::sendToServer(querySort);
}

void Pagination::initializationModels()
{
    int setPages = currentPage - currentPageInModel();

    int startOffset = setPages * rowsPerPage;
    int nextOffset = (setPages + maxPageModel) * rowsPerPage;
    int prevOffset = (setPages - maxPageModel) * rowsPerPage;

    emit blockInterface(false);

    loadingModel(ModelLoadingType::Central, startOffset);
    loadingModel(ModelLoadingType::Next, nextOffset);
    loadingModel(ModelLoadingType::Prev, prevOffset);
}

void Pagination::loadingMaxPage()
{
    if (P_SendModel::tableNames.size() == 0)
        P_SendModel::initMapTableNames();

    PacketTypes packettype = PacketTypes::P_Query;
    QString query = "SELECT COUNT(*) FROM " + P_SendModel::tableNames[modelTypes];

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
    searchTimer.setSingleShot(true);
}

void Pagination::connects()
{
    connect(NetworkClient::packetHandler, &PacketHandler::signalSetQueryModel, this, &Pagination::distributor);
    connect(&searchTimer, &QTimer::timeout, this, &Pagination::searchInDB);
}

void Pagination::goToPage(QString page)
{
    if(page.isEmpty())
        return;

    int currentPage = page.toInt();
    int setPages = this->currentPage - currentPageInModel();

    this->currentPage = (currentPage > maxPage) ? maxPage : currentPage;

    if(setPages < this->currentPage && this->currentPage <= (setPages + maxPageModel))
        updateTablePage();
    else
        initializationModels();
}

void Pagination::search(QString searchText, QString typeSearch, QComboBox* column)
{
    if(searchText.isEmpty())
        return;

    this->searchText = searchText;
    this->typeSearch = typeSearch;
    this->column = column;

    searchInModel();
}

void Pagination::searchInModel()
{
    for (QSharedPointer<QStandardItemModel> model : models)
    {
        if(searchModule->searchInModels(model, searchText, typeSearch, column->currentIndex(), currentPage, rowsPerPage))
        {
            searchText.clear();
            typeSearch.clear();
            updateTablePage();
            return;
        }
    }

    searchTimer.start(1000);
}

void Pagination::searchInDB()
{
    searchModule->searchInDB(modelTypes, P_SendModel::tableNames[modelTypes], column->currentText(), searchText + typeSearch, querySort);
}

void Pagination::distributor(QueryData* data)
{
    if(data->modelTypes != modelTypes)
        return;

    switch (data->queryTypes)
    {
    case QueryTypes::CountEntrites:
        setMaxPage(data->result);
        break;

    case QueryTypes::Search:
    {
        QString page = QString::number(std::ceil(data->result.toDouble() / rowsPerPage));
        goToPage(page);
        break;
    }

    default:
        Message::logWarn("Тип запроса не известен");
        break;
    }
}

void Pagination::reloadModels()
{
    currentPage = 1;
    loadingMaxPage();
    initializationModels();
}

void Pagination::setSort(QString sort)
{
    querySort = sort;
}
