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

    bool searchInModels(QSharedPointer<QStandardItemModel> model, QString searchText, QString typeSearch, int columnCurrentIndex, int& currentPage, int rowsPerPage);
    void searchInDB(ModelTypes modelType, QString searchText);
};

#endif // SEARCH_H
