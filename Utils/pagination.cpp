#include "pagination.h"
#include <QDebug>

Pagination::Pagination(QWidget* parent, QTableView* table, QPushButton* prevButton, QPushButton* nextButton) :
    QWidget(parent),
    _tableView(table),
    _prevButton(prevButton),
    _nextButton(nextButton)
{}

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
//                if(_models[2]->rowCount() != 0)
//                    goToPrevModel();
//            }
//            else
                _prevButton->setEnabled(false);
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
    if(_currentPage < getMaxPage())
    {
        _prevButton->setEnabled(true);
        if(currentPageInModel() == _maxPageModel)
        {
//            if(!_nextTreadModel->isRun())
//            {
//                if(_models[1]->rowCount() != 0)
//                    goToNextModel();
//            }
//            else
                _nextButton->setEnabled(false);
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
