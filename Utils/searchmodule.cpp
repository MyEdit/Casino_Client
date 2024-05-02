#include "searchmodule.h"

void SearchModule::searchInModels(QVector<QSharedPointer<QStandardItemModel>>& models, const QString& searchText, const QString& typeSearch, int columnCurrentIndex, int rowsPerPage)
{
    std::thread([&models, searchText, typeSearch, columnCurrentIndex, rowsPerPage, this]()
    {
//        QThread::sleep(5);
        for (QSharedPointer<QStandardItemModel> model : models)
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
                    int currentPage = std::ceil(resultRow / rowsPerPage);
                    QSharedPointer<ResultSearchInModel> result(new ResultSearchInModel{model, index, currentPage});
                    emit signalResulSearchInModel(result);
                    return;
                }
            }
        }
        emit signalNothingWasFoundInModel();
    }).detach();
}


void SearchModule::searchInDB(ModelTypes modelType, const QString& table, const QString& column, const QString& searchText, const QString& sort)
{
    PacketTypes packettype = PacketTypes::P_Query;
    QueryTypes queryTypes = QueryTypes::Search;
    QString query = "SELECT numbered_rows.№ FROM (SELECT ROW_NUMBER() OVER (" + sort + ") AS №, * FROM " + table + ") AS numbered_rows WHERE numbered_rows." + column + " LIKE '" + searchText + "'";

    NetworkClient::sendToServer(&packettype, sizeof(PacketTypes));
    NetworkClient::sendToServer(&queryTypes, sizeof(QueryTypes));
    NetworkClient::sendToServer(&modelType, sizeof(ModelTypes));
    NetworkClient::sendToServer(query);
}
