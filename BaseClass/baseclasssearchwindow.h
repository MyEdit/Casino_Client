#ifndef BASECLASSSEARCHWINDOW_H
#define BASECLASSSEARCHWINDOW_H

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
    QSharedPointer<Pagination> pagination;
    QSharedPointer<WorkingIsTableView> workingIsTableView;
    ModelTypes modelTypes;
    QTimer goToPageTimer;
    QString typeSearch;
    bool sortingOn;
    QMap<int, QString> typesSorting;

public:
    BaseClassSearchWindow(QWidget *parent);

    void setModel(QSharedPointer<ModelData> model);

protected:
    void workingWithTableView();
    void blockAndOperate(QObject* widget, const std::function<void()>& operation);
    void blockingInterface(const bool flag);
    void settingValueInComboBox(QComboBox* comboBox, const QString& headerText);
    void sorting(int arg);
    void selectTypeSearch(int arg);
    void baseSetting();
    void sort();
    void deleteRecord(const QString& table, const QString& idColumn, int id);
    const QVariant getValueFromSelectedRow(QTableView* tableView, int collumn);
    virtual void search() = 0;
    virtual void setValueToMaxPage(const int maxPage) = 0;
    virtual void assigningValues() = 0;
    virtual void creatingObjects() = 0;
    virtual void connects() = 0;
    virtual void updateCurrentPageInLabel(const int currentPage) = 0;
    virtual void goToPage() = 0;
    virtual void onHeaderClicked(const int logicalIndex) = 0;
    virtual void prepReloadModels() = 0;
    virtual void openCreatRecotd() {};
    virtual void openEditRecotd() {};
    virtual void deleting() {};
};

#endif // BASECLASSSEARCHWINDOW_H
