﻿#ifndef BASECLASSSEARCHWINDOW_H
#define BASECLASSSEARCHWINDOW_H

#include <QWidget>
#include <QVector>
#include <QComboBox>
#include <QTimer>
#include <QPushButton>
#include <QCheckBox>
#include <QComboBox>
#include <QLineEdit>
#include "Utils/workingistableview.h"
#include "BaseClass/baseclasfilter.h"

class Pagination;

class BaseClassSearchWindow : public QWidget
{
    Q_OBJECT

protected:
    QVector<QComboBox*> boxsNameColumn;
    QSharedPointer<Pagination> pagination;
    QSharedPointer<WorkingIsTableView> workingIsTableView;
    ModelTypes modelTypes;
    QTimer goToPageTimer;
    QTimer searchTimer;
    QString typeSearch;
    bool sortingOn;
    QMap<int, QString> typesSorting;
    QWidget* focusedWidget;
    QString defaultFilter;
    QSharedPointer<BaseClasFilter> filter;

public:
    BaseClassSearchWindow(QWidget *parent);

    void setModel(QSharedPointer<ModelData> model);
    virtual void update();

protected:
    void workingWithTableView();
    void blockAndOperate(QObject* widget, const std::function<void()>& operation);
    void blockingInterface(const bool flag);
    void settingValueInComboBox(QComboBox* comboBox, const QString& headerText);
    void sorting(const int arg);
    void selectTypeSearch(const int arg);
    void baseSetting();
    void sort();
    void deleteRecord(const QString& table, const QString& idColumn, const int id);
    void startPagination();
    const QVariant getValueFromSelectedRow(QTableView* tableView, const int collumn);
    void showEvent(QShowEvent *event) override;
    virtual void search() = 0;
    virtual void setValueToMaxPage(const int maxPage) = 0;
    virtual void assigningValues();
    virtual void creatingObjects() = 0;
    virtual void connects();
    virtual void updateCurrentPageInLabel(const int currentPage) = 0;
    virtual void goToPage() = 0;
    virtual void onHeaderClicked(const int logicalIndex) = 0;
    virtual void prepReloadModels() = 0;
    virtual void openCreatRecotd() = 0;
    virtual void openEditRecotd() = 0;
    virtual void deleting() = 0;
    virtual void clearSearchText() = 0;
    virtual void visibleSort(const bool flag) = 0;
    virtual void visibleSearch(const bool flag) = 0;
    virtual void visibleEditing(const bool flag) = 0;
    virtual void visibleFiltr(const bool flag) = 0;
    virtual void addFilter() = 0;
    virtual void clearFilter();
    virtual void setFilter(const QString& filter);
    virtual void runSearch() = 0;
    virtual void runGoToPage() = 0;
};

#endif // BASECLASSSEARCHWINDOW_H
