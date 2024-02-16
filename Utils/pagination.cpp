#include "pagination.h"
#include <QDebug>

Pagination::Pagination(QWidget* parent, QTableView* table, QPushButton* prevButton, QPushButton* nextButton, WorkingIsTableView* workingIsTableView) :
    QWidget(parent),
    _tableView(table),
    _prevButton(prevButton),
    _nextButton(nextButton),
    _workingIsTableView(workingIsTableView)
{
    for(int i = 0; i < 3; i++)
        _models.push_back(QSharedPointer<QStandardItemModel>::create());
}

void Pagination::updateTablePage()
{
    int startIndex = (currentPageInModel() - 1) * _rowsPerPage;
    int endIndex = startIndex + _rowsPerPage;

    int rowCountModel = _tableView->model()->rowCount();
    for (int row = 0; row < rowCountModel; row++)
    {
        bool rowVisible = (row >= startIndex && row < endIndex);
        _tableView->setRowHidden(row, !rowVisible);
    }

    emit updateCurrentPageInLabel(_currentPage);
}

int Pagination::currentPageInModel()
{
    int pageModel = _currentPage % _maxPageModel;

    if(pageModel == 0)
        pageModel = _maxPageModel;

    return pageModel;
}

void Pagination::setMaxPage(QString rowCount)
{
    _maxPage = static_cast<int>(std::ceil(rowCount.toDouble() / _rowsPerPage));
}

int Pagination::getMaxPage()
{
    return _maxPage;
}

void Pagination::prev()
{
    if(_currentPage > 1)
    {
        _nextButton->setEnabled(true);
        if(currentPageInModel() == _minPageModel)
        {
//            if (!_prevTreadModel->isRunning())
//            {
                if(_models[2]->rowCount() != 0)
                    goToPrevModel();
//            }
//            else
//                _prevButton->setEnabled(false);
        }
        else
        {
            _currentPage--;
            updateTablePage();
        }
    }
}

void Pagination::next()
{
    if(_currentPage < _maxPage)
    {
        _prevButton->setEnabled(true);
        if(currentPageInModel() == _maxPageModel)
        {
//            if(!_nextTreadModel->isRun())
//            {
                if(_models[1]->rowCount() != 0)
                    goToNextModel();
//            }
//            else
//                _nextButton->setEnabled(false);
        }
        else
        {
            _currentPage++;
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
        _models[1] = QSharedPointer<QStandardItemModel>(structModel.model);
        break;

    case ModelLoadingType::Central:
        _models[0] = QSharedPointer<QStandardItemModel>(structModel.model);
        _workingIsTableView->setModel(_models[0].data());
        break;

    case ModelLoadingType::Prev:
        _models[2] = QSharedPointer<QStandardItemModel>(structModel.model);
        break;
    }
}

void Pagination::goToNextModel()
{
    _currentPage++;

    _workingIsTableView->setModel(_models[1].data());
    std::rotate(_models.begin(), _models.begin() + 1, _models.end());

    int nextOffset = (_currentPage + _maxPageModel - 1) * _rowsPerPage;
    loadingModel(ModelLoadingType::Next, nextOffset);
    updateTablePage();
}

void Pagination::goToPrevModel()
{
    _currentPage--;

    _workingIsTableView->setModel(_models[2].data());
    std::rotate(_models.begin(), _models.begin() + (_models.size() - 1), _models.end());

    int prevOffset = (_currentPage - _maxPageModel * 2) * _rowsPerPage;
    loadingModel(ModelLoadingType::Prev, prevOffset);

    updateTablePage();
}

void Pagination::loadingModel(ModelLoadingType type, int offset)
{
    PacketTypes packettype = PacketTypes::P_SendModel;
    ModelTypes existingTables = ModelTypes::ActiveTables;
    NetworkClient::sendToServer(&packettype, sizeof(PacketTypes));
    NetworkClient::sendToServer(&type, sizeof(ModelLoadingType));
    NetworkClient::sendToServer(&existingTables, sizeof(ModelTypes));
    NetworkClient::sendToServer(&offset, sizeof(int));
}



