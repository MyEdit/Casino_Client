﻿#include "pagination.h"
#include <QDebug>

Pagination::Pagination(QWidget* parent, QTableView* table, QPushButton* prevButton, QPushButton* nextButton, QComboBox* column, QSharedPointer<WorkingIsTableView> workingIsTableView, ModelTypes modelTypes) :
    QWidget(parent),
    tableView(table),
    prevButton(prevButton),
    nextButton(nextButton),
    workingIsTableView(workingIsTableView),
    modelTypes(modelTypes),
    column(column)
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
    if(currentPage > 1)
    {
        nextButton->setEnabled(true);
        if(currentPageInModel() == minPageModel)
        {
            if(goToPrev)
            {
                if(models[2]->rowCount() != 0)
                {
                    goToPrevModel();
                    return;
                }
            }
            int prevOffset = (currentPage - maxPageModel) * rowsPerPage;
            loadingModel(ModelLoadingType::Prev, prevOffset);
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
    if (currentPage < maxPage)
    {
        prevButton->setEnabled(true);
        if (currentPageInModel() == maxPageModel)
        {
            if (goToNext)
            {
                if (models[1]->rowCount() != 0)
                {
                    goToNextModel();
                    return;
                }
            }
            else
            {
                int nextOffset = currentPage * rowsPerPage;
                loadingModel(ModelLoadingType::Next, nextOffset);
            }
        }
        else
        {
            currentPage++;
            updateTablePage();
        }
    }
    else
    {
        QMessageBox::warning(this, "Внимание", "Данных больше нет!", QMessageBox::Ok);
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
}

void Pagination::initializationModels()
{
    std::thread([&]()
    {
        int setPages = currentPage - currentPageInModel();

        int centralOffset = setPages * rowsPerPage;
        int nextOffset = (setPages + maxPageModel) * rowsPerPage;
        int prevOffset = (setPages - maxPageModel) * rowsPerPage;

        emit blockInterface(false);

        loadingModel(ModelLoadingType::Central, centralOffset);
        loadingModel(ModelLoadingType::Next, nextOffset);
        loadingModel(ModelLoadingType::Prev, prevOffset);
    }).detach();
}

void Pagination::loadingMaxPage()
{
    PacketTypes packettype = PacketTypes::P_Query;
    QString query = "SELECT COUNT(*) FROM " + P_SendModel::getTableName(modelTypes);

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
}

void Pagination::goToPage(const QString& page)
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

    searchInDB();
}

void Pagination::searchInDB()
{
    searchModule->searchInDB(modelTypes, P_SendModel::getTableName(modelTypes), column->currentText(), searchText + typeSearch, querySort);
}

void Pagination::distributor(QSharedPointer<QueryData> data)
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

void Pagination::setSort(const QString& sort)
{
    querySort = sort;
}
