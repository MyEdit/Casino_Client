#ifndef PAGINATION_H
#define PAGINATION_H

#include <QTableView>
#include <math.h>
#include <QWidget>
#include <QMessageBox>
#include <QPushButton>

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

public:
    Pagination(QWidget* parent, QTableView* table, QPushButton* prevButton, QPushButton* nextButton);

    int getMaxPage();
    int currentPageInModel();
    void updateTablePage();
    void prev();
    void next();
    void setMaxPage(QString rowCount);
};

#endif // PAGINATION_H
