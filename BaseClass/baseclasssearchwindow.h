#ifndef BASECLASSSEARCHWINDOW_H
#define BASECLASSSEARCHWINDOW_H

//#include "Utils/pagination.h"
#include "Utils/workingistableview.h"

#include <QWidget>
#include <QVector>
#include <QComboBox>
#include <QTimer>
#include <QPushButton>
#include <QCheckBox>
#include <QComboBox>
#include <QLineEdit>

class Pagination;

class BaseClassSearchWindow : public QWidget
{
    Q_OBJECT

protected:
    QVector<QComboBox*> boxsNameColumn;
    Pagination* pagination;
    WorkingIsTableView* workingIsTableView;
    ModelTypes modelTypes;
    QTimer goToPageTimer;
    QString typeSearch;
    bool sortingOn;
    QMap<int, QString> typesSorting;

public:
    BaseClassSearchWindow(QWidget *parent);

    void setModel(ModelData model);

protected:
    void workingWithTableView();
    void blockAndOperate(QObject* widget, const std::function<void()>& operation);
    void blockingInterface(bool flag);
    void settingValueInComboBox(QComboBox* comboBox, QString& headerText);
    void sorting(int arg);
    void selectTypeSearch(int arg);
    void baseSetting();
    virtual void search() = 0;
    virtual void setValueToMaxPage(int maxPage) = 0;
    virtual void assigningValues() = 0;
    virtual void creatingObjects() = 0;
    virtual void connects() = 0;
    virtual void updateCurrentPageInLabel(int currentPage) = 0;
    virtual void goToPage() = 0;
    virtual void onHeaderClicked(int logicalIndex) = 0;
    virtual void prepReloadModels() = 0;
};

#endif // BASECLASSSEARCHWINDOW_H
