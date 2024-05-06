#ifndef PAGINATION_H
#define PAGINATION_H

#include <QTableView>
#include <math.h>
#include <QWidget>
#include <QMessageBox>
#include <QPushButton>
#include <QLabel>
#include "Utils/workingistableview.h"
#include "Utils/searchmodule.h"
#include "Network/networkclient.h"
#include "QTimer"

class SearchModule;

class Pagination : public QWidget
{
    Q_OBJECT

    QTableView* tableView;
    int currentPage;
    int rowsPerPage;
    int maxPageModel;
    int minPageModel;
    int maxPage;
    QSharedPointer<WorkingIsTableView> workingIsTableView;
    QSharedPointer<SearchModule> searchModule;
    QVector<QSharedPointer<QStandardItemModel>> models;
    ModelTypes modelTypes;
    QString searchText;
    QString typeSearch;
    QComboBox* column;
    bool goToNext = false;
    bool goToPrev = false;
    QString querySort {};
    QString where;

public:
    Pagination(QWidget* parent, QTableView* table, QComboBox* column, QSharedPointer<WorkingIsTableView> workingIsTableView, ModelTypes modelTypes);

    int getMaxPage();
    void prev();
    void next();
    void acceptModel(QSharedPointer<ModelData> structModel);
    void goToPage(const QString& page);
    void search(const QString& searchText, const QString& typeSearch);
    void reloadModels();
    void start();
    void setSort(const QString& sort);
    void initializationModels();
    void setWhere(const QString& where);

private:
    void goToNextModel();
    void goToPrevModel();
    void loadingModel(const ModelLoadingType type, const int offset);
    void assigningValues();
    void connects();
    void creatingObjects();
    void distributor(QSharedPointer<QueryData> data);
    void loadingMaxPage();
    void updateTablePage();
    int currentPageInModel();
    void setMaxPage(const QString& rowCount);
    void searchInModel();
    void searchInDB();
    void dataFoundInModel(QSharedPointer<ResultSearchInModel> resultSearch);
    void resultSearchInDB(QPair<ModelTypes, QString> result);

signals:
    void updateCurrentPageInLabel(int);
    void setMaxPageInLabel(int);
    void blockInterface(const bool);
};

#endif // PAGINATION_H
