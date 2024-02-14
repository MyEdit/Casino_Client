#ifndef EXISTINGTABLES_H
#define EXISTINGTABLES_H

#include <QWidget>
#include "QStandardItemModel"
#include "Utils/Message.h"
#include "Network/PacketTypes.h"
#include "Network/networkclient.h"
#include <QMutex>
#include <math.h>
#include <QTimer>
#include <QMessageBox>
#include "Utils/pagination.h"

class Window_Admin;

namespace Ui {
class ExistingTables;
}

class ExistingTables : public QWidget
{
    Q_OBJECT
    Ui::ExistingTables *ui;
    QVector<QString> _headers;
    int _currentPage;
    int _rowsPerPage;
    bool _sortingOn;
    QString _filter;
    QString _columtSort;
    QString _typeSort;
    QString _typeSearch;
    QMutex _mutex;
    QTimer _resizeTimer;
    QString _like;
    QString _column;
    QTimer _searchTimer;
    QTimer _goToPageTimer;
    QMap<int, QString> _typesSorting;
    QVector<QSharedPointer<QStandardItemModel>> _models;
    Pagination* pagination;

public:
    explicit ExistingTables(QWidget *parent = nullptr);
    ~ExistingTables();

    void setModel(QStandardItemModel* model);

private:
    void workingWithTableView();
    void setValueNameColumn();
    QVector<QString> getColumnHeaders();
    void setValueToMaxPage(QString rowCount);
    void assigningValues();
    void updateTablePage();
    void updateCurrentPageInLabel();
    void searchInModels();
    void creatingObjects();
    void connects();
    void getMaxPage();

private slots:
    void on_searchText_textChanged(const QString &arg1);
};

#endif // EXISTINGTABLES_H
