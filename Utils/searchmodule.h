#ifndef SEARCH_H
#define SEARCH_H

#include "Utils/workingistableview.h"
#include "Network/networkclient.h"
#include <math.h>

class SearchModule : public QObject
{
    Q_OBJECT

public:
    SearchModule() {}

    void searchInModels(QVector<QSharedPointer<QStandardItemModel>> models, const QString& searchText, const QString& typeSearch, int columnCurrentIndex, int rowsPerPage);
    static void searchInDB(ModelTypes modelType, const QString& table, const QString& column, const QString& searchText, const QString& sort);

signals:
    void signalResulSearchInModel(QSharedPointer<ResultSearchInModel>);
    void signalNothingWasFoundInModel(); //если в моделях ничего не найдено
};

#endif // SEARCH_H
