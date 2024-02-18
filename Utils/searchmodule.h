#ifndef SEARCH_H
#define SEARCH_H

#include "Utils/pagination.h"
class Pagination;

class SearchModule
{
    Pagination* pagination;
    WorkingIsTableView* workingIsTableView;

public:
    SearchModule(Pagination* pagination, WorkingIsTableView* workingIsTableView);

    void searchInModels(QSharedPointer<QStandardItemModel> model, QString searchText, QString typeSearch, int columnCurrentIndex, int& currentPage, int rowsPerPage);
};

#endif // SEARCH_H
