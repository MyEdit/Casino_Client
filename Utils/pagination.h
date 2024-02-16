#ifndef PAGINATION_H
#define PAGINATION_H

#include <QTableView>
#include <math.h>
#include <QWidget>
#include <QMessageBox>
#include <QPushButton>
#include "Utils/workingistableview.h"
#include "Network/networkclient.h"

class Pagination : public QWidget
{
    Q_OBJECT

    QTableView* _tableView;
    QPushButton* _prevButton;
    QPushButton* _nextButton;
    int _currentPage = 1;
    int _rowsPerPage = 10;
    int _maxPageModel = 5;
    int _minPageModel = 1;
    int _maxPage;
    WorkingIsTableView* _workingIsTableView;
    QVector<QSharedPointer<QStandardItemModel>> _models;
    ModelTypes _modelTypes = ModelTypes::ActiveTables; //Перенести в кноструктор

public:
    Pagination(QWidget* parent, QTableView* table, QPushButton* prevButton, QPushButton* nextButton, WorkingIsTableView* workingIsTableView);

    int getMaxPage();
    int currentPageInModel();
    void updateTablePage();
    void prev();
    void next();
    void setMaxPage(QString rowCount);
    void acceptModel(ModelData structModel);

private:
    void goToNextModel();
    void goToPrevModel();
    void loadingModel(ModelLoadingType type, int offset);

signals:
    int updateCurrentPageInLabel(int currentPage);
};

#endif // PAGINATION_H
