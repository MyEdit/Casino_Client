#ifndef SEARCH_H
#define SEARCH_H

#include "Utils/workingistableview.h"
#include "Network/networkclient.h"
#include <math.h>

class SearchModule
{
    QSharedPointer<WorkingIsTableView> workingIsTableView;

public:
    SearchModule(QSharedPointer<WorkingIsTableView> workingIsTableView);

    bool searchInModels(QSharedPointer<QStandardItemModel> model, QString searchText, QString typeSearch, int columnCurrentIndex, int& currentPage, int rowsPerPage);
    void searchInDB(ModelTypes modelType, QString table, QString column, QString searchText, QString sort);
};

#endif // SEARCH_H
