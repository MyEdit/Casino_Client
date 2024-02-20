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

class SearchModule;

class Pagination : public QWidget
{
    Q_OBJECT

    QTableView* tableView;
    QPushButton* prevButton;
    QPushButton* nextButton;
    int currentPage;
    int rowsPerPage;
    int maxPageModel;
    int minPageModel;
    int maxPage;
    WorkingIsTableView* workingIsTableView;
    SearchModule* searchModule;
    QVector<QSharedPointer<QStandardItemModel>> models;
    ModelTypes modelTypes;
    QString searchText;
    QString typeSearch;
    QComboBox* column;
    QTimer searchTimer;

public:
    Pagination(QWidget* parent, QTableView* table, QPushButton* prevButton, QPushButton* nextButton, WorkingIsTableView* workingIsTableView, ModelTypes modelTypes);

    int getMaxPage();
    int currentPageInModel();
    void updateTablePage();
    void prev();
    void next();
    void setMaxPage(QString rowCount);
    void acceptModel(ModelData structModel);
    void loadingMaxPage();
    void goToPage(QString page);
    void start();
    void search(QString searchText, QString typeSearch, QComboBox* column);
    void searchInDb();

private:
    void goToNextModel();
    void goToPrevModel();
    void loadingModel(ModelLoadingType type, int offset);
    void initializationStartModel();
    void assigningValues();
    void connects();
    void creatingObjects();
    void distributor(QueryData* data);

signals:
    void updateCurrentPageInLabel(int);
    void setMaxPageInLabel(int);
    void blockInterface(bool);
};

#endif // PAGINATION_H
