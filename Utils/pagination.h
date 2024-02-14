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
    int _currentPage;
    int _rowsPerPage;
    int _maxPageModel;
    int _minPageModel;
    int _maxPage;

public:
    Pagination(QWidget* parent, QTableView* table, QPushButton* prevButton, QPushButton* nextButton);

    void updateTablePage();
    int currentPageInModel();
    void setMaxPage(QString rowCount);
    int getMaxPage();
    void prev();
    void next();

private:
    void assigningValues();
};

#endif // PAGINATION_H
