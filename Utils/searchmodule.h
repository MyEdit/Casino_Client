#ifndef SEARCH_H
#define SEARCH_H

#include "Utils/workingistableview.h"
#include "Network/networkclient.h"
#include <math.h>

class Pagination;

class SearchModule
{
    WorkingIsTableView* workingIsTableView;

public:
    SearchModule(WorkingIsTableView* workingIsTableView);

    bool searchInModels(QSharedPointer<QStandardItemModel> model, QString searchText, QString typeSearch, int columnCurrentIndex, int& currentPage, int rowsPerPage);
    void searchInDB(ModelTypes modelType, QString searchText);
};

#endif // SEARCH_H
