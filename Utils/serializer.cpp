#include "serializer.h"

QStandardItemModel* Serializer::deserializationDataModel(QByteArray receivedData)
{
    QStandardItemModel* model = new QStandardItemModel();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(receivedData);

    if (!jsonDoc.isNull() && jsonDoc.isObject())
    {
        QJsonObject resultObject = jsonDoc.object();
        QJsonArray rowsArray = resultObject["rows"].toArray();

        for (const QJsonValue& rowValue : rowsArray)
        {
            QJsonObject rowObject = rowValue.toObject();
            QList<QStandardItem*> rowItems;
            for (const QString& key : rowObject.keys())
            {
                QStandardItem* item = new QStandardItem(rowObject[key].toString());
                rowItems.append(item);
            }
            model->appendRow(rowItems);
        }
    }

    return  model;
}
