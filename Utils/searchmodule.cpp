#include "searchmodule.h"

SearchModule::SearchModule(QSharedPointer<WorkingIsTableView> workingIsTableView) :
    workingIsTableView(workingIsTableView)
{

}

bool SearchModule::searchInModels(QSharedPointer<QStandardItemModel> model, QString searchText, QString typeSearch, int columnCurrentIndex, int& currentPage, int rowsPerPage)
{
    bool resultSearchInModel = false;
    for (int row = 0; row < model->rowCount(); row++)
    {
        QModelIndex index = model->index(row, columnCurrentIndex + 1);
        QVariant data = model->data(index);

        if (typeSearch == "%")
            resultSearchInModel = data.toString().startsWith(searchText, Qt::CaseInsensitive);
        else
            resultSearchInModel = (data.toString().compare(searchText, Qt::CaseInsensitive) == 0);

        if (resultSearchInModel)
        {
            double resultRow = model->data(model->index(row, 0)).toDouble();
            currentPage = std::ceil(resultRow / rowsPerPage);
            workingIsTableView->setModel(model);
            workingIsTableView->setCurrentIndex(index);
            return resultSearchInModel;
        }
    }

    return resultSearchInModel;
}

void SearchModule::searchInDB(ModelTypes modelType, QString table, QString column, QString searchText, QString sort)
{
    PacketTypes packettype = PacketTypes::P_QueryWithoutResponce;
    QueryTypes queryTypes = QueryTypes::Search;
    QString query = "SELECT numbered_rows.№ FROM (SELECT ROW_NUMBER() OVER (" + sort + ") AS №, * FROM " + table + ") AS numbered_rows WHERE numbered_rows." + column + " LIKE '" + searchText + "'";

    NetworkClient::sendToServer(&packettype, sizeof(PacketTypes));
    NetworkClient::sendToServer(&queryTypes, sizeof(QueryTypes));
    NetworkClient::sendToServer(&modelType, sizeof(ModelTypes));
    NetworkClient::sendToServer(query);
}
