﻿#include "pagination.h"
#include <QDebug>

Pagination::Pagination(QWidget* parent, QTableView* table, QPushButton* prevButton, QPushButton* nextButton, WorkingIsTableView* workingIsTableView, ModelTypes modelTypes) :
    QWidget(parent),
    tableView(table),
    prevButton(prevButton),
    nextButton(nextButton),
    workingIsTableView(workingIsTableView),
    modelTypes(modelTypes)
{
    for(int i = 0; i < 3; i++)
        models.push_back(QSharedPointer<QStandardItemModel>::create());

    assigningValues();
    connects();
}

void Pagination::start()
{
    loadingMaxPage();
    initializationStartModel();
}

void Pagination::updateTablePage()
{
    int startIndex = (currentPageInModel() - 1) * rowsPerPage;
    int endIndex = startIndex + rowsPerPage;

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

void Pagination::setMaxPage(QueryData *resultQuery)
{
    if(resultQuery->modelTypes == modelTypes)
    {
        QString rowCount = resultQuery->result;
        maxPage = static_cast<int>(std::ceil(rowCount.toDouble() / rowsPerPage));
        emit setMaxPageInLabel(maxPage);
    }
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
            //            if (!prevTreadModel->isRunning())
            //            {
            if(models[2]->rowCount() != 0)
                goToPrevModel();
            //            }
            //            else
            //                prevButton->setEnabled(false);
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
            //            if(!nextTreadModel->isRun())
            //            {
            if(models[1]->rowCount() != 0)
                goToNextModel();
            //            }
            //            else
            //                nextButton->setEnabled(false);
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
        workingIsTableView->setModel(models[0].data());
        updateTablePage();
        break;

    case ModelLoadingType::Prev:
        models[2] = QSharedPointer<QStandardItemModel>(structModel.model);
        break;
    }
}

void Pagination::goToNextModel()
{
    currentPage++;

    workingIsTableView->setModel(models[1].data());
    std::rotate(models.begin(), models.begin() + 1, models.end());

    int nextOffset = (currentPage + maxPageModel - 1) * rowsPerPage;
    loadingModel(ModelLoadingType::Next, nextOffset);
    updateTablePage();
}

void Pagination::goToPrevModel()
{
    currentPage--;

    workingIsTableView->setModel(models[2].data());
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
}

void Pagination::initializationStartModel()
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
    PacketTypes packettype = PacketTypes::P_QueryWithoutResponce;
    QueryTypes queryTypes = QueryTypes::CountEntrites;

    NetworkClient::sendToServer(&packettype, sizeof(PacketTypes));
    NetworkClient::sendToServer(&queryTypes, sizeof(QueryTypes));
    NetworkClient::sendToServer(&modelTypes, sizeof(ModelTypes));
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
    connect(NetworkClient::packetHandler, &PacketHandler::signalSetQueryModel, this, &Pagination::setMaxPage);
}

void Pagination::goToPage(int currentPage)
{
    int setPages = this->currentPage - currentPageInModel();

    this->currentPage = (currentPage > maxPage) ? maxPage : currentPage;

    if(setPages < this->currentPage && this->currentPage <= (setPages + maxPageModel))
        updateTablePage();
    else
        initializationStartModel();
}
