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

    bool searchInModels(QSharedPointer<QStandardItemModel> model, const QString& searchText, const QString& typeSearch, int columnCurrentIndex, int& currentPage, int rowsPerPage);
    void searchInDB(ModelTypes modelType, const QString& table, const QString& column, const QString& searchText, const QString& sort);
};

#endif // SEARCH_H
