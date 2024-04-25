﻿#ifndef PAGINATION_H
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
    QPushButton* prevButton;
    QPushButton* nextButton;
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
    QString querySort;
    QTimer searchTimer;

public:
    Pagination(QWidget* parent, QTableView* table, QPushButton* prevButton, QPushButton* nextButton, QComboBox* column, QSharedPointer<WorkingIsTableView> workingIsTableView, ModelTypes modelTypes);

    int getMaxPage();
    void prev();
    void next();
    void acceptModel(QSharedPointer<ModelData> structModel);
    void goToPage(const QString& page);
    void search(const QString& searchText, const QString& typeSearch);
    void reloadModels();
    void start();
    void setSort(const QString& sort);

private:
    void goToNextModel();
    void goToPrevModel();
    void loadingModel(ModelLoadingType type, int offset);
    void initializationModels();
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

signals:
    void updateCurrentPageInLabel(int);
    void setMaxPageInLabel(int);
    void blockInterface(bool);
};

#endif // PAGINATION_H
