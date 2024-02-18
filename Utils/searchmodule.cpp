#include "searchmodule.h"

SearchModule::SearchModule(Pagination* pagination, WorkingIsTableView *workingIsTableView) :
    pagination(pagination),
    workingIsTableView(workingIsTableView)
{

}

bool SearchModule::searchInModels(QSharedPointer<QStandardItemModel> model, QString searchText, QString typeSearch, int columnCurrentIndex, int& currentPage, int rowsPerPage)
{
    bool resultSearchInModel = false;
    for (int row = 0; row < model->rowCount(); row++)
    {
        QModelIndex index = model->index(row, columnCurrentIndex);
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
            break;
        }
    }

    return resultSearchInModel;
}

void SearchModule::searchInDB(ModelTypes modelType, QString searchText)
{
    PacketTypes packettype = PacketTypes::P_QueryWithoutResponce;
    QueryTypes queryTypes = QueryTypes::Search;

    NetworkClient::sendToServer(&packettype, sizeof(PacketTypes));
    NetworkClient::sendToServer(&queryTypes, sizeof(QueryTypes));
    NetworkClient::sendToServer(&modelType, sizeof(ModelTypes));
    NetworkClient::sendToServer(searchText);
}
