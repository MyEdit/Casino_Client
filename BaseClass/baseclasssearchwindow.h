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


class BaseClassSearchWindow : public QWidget
{
    Q_OBJECT

protected:
    QVector<QComboBox*> boxsNameColumn;
//    Pagination* pagination;
    WorkingIsTableView* workingIsTableView;
    ModelTypes modelTypes;
    QTimer goToPageTimer;
    QString typeSearch;
    bool sortingOn;

public:
    BaseClassSearchWindow(QWidget *parent);

protected:
    void workingWithTableView();
    void blockAndOperate(QObject* widget, const std::function<void()>& operation);
    void blockingInterface(bool flag);
    void settingValueInComboBox(QComboBox* comboBox, QString& headerText);
};

#endif // BASECLASSSEARCHWINDOW_H
