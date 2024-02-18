#ifndef PAGINATION_H
#define PAGINATION_H

#include <QTableView>
#include <math.h>
#include <QWidget>
#include <QMessageBox>
#include <QPushButton>
#include <QLabel>
#include "Utils/workingistableview.h"
#include "Network/networkclient.h"

class Pagination : public QWidget
{
    Q_OBJECT

    QTableView* tableView;
    QPushButton* prevButton;
    QPushButton* nextButton;
    int currentPage = 1;
    int rowsPerPage = 10;
    int maxPageModel = 5;
    int minPageModel = 1;
    int maxPage;
    WorkingIsTableView* workingIsTableView;
    QVector<QSharedPointer<QStandardItemModel>> models;
    ModelTypes modelTypes;

public:
    Pagination(QWidget* parent, QTableView* table, QPushButton* prevButton, QPushButton* nextButton, WorkingIsTableView* workingIsTableView, ModelTypes modelTypes);

    int getMaxPage();
    int currentPageInModel();
    void updateTablePage();
    void prev();
    void next();
    void setMaxPage(QueryData* rowCount);
    void acceptModel(ModelData structModel);
    void loadingMaxPage();
    void goToPage(int currentPage);
    void start();

private:
    void goToNextModel();
    void goToPrevModel();
    void loadingModel(ModelLoadingType type, int offset);
    void initializationStartModel();
    void assigningValues();
    void connects();

signals:
    void updateCurrentPageInLabel(int);
    void setMaxPageInLabel(int);
    void blockInterface(bool);
};

#endif // PAGINATION_H
