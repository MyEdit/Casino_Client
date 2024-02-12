#include "serializer.h"

QStandardItemModel* Serializer::deserializationDataModel(QByteArray receivedData)
{
    QStandardItemModel* model = new QStandardItemModel();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(receivedData);
    if (!jsonDoc.isNull() && jsonDoc.isArray())
    {
        QJsonArray rowsArray = jsonDoc.array();

        QStringList headers;
        if (!rowsArray.isEmpty() && rowsArray.first().isObject())
        {
            QJsonObject headerObject = rowsArray.first().toObject();
            if (headerObject.contains("headers"))
            {
                QJsonArray headerArray = headerObject["headers"].toArray();
                for (const auto& headerValue : headerArray)
                {
                    if (headerValue.isString())
                        headers.append(headerValue.toString());
                }
            }
        }

        for (int i = 1; i < rowsArray.size(); ++i)
        {
            QJsonObject rowObject = rowsArray[i].toObject();
            QList<QStandardItem*> rowItems;
            for (const QString& header : headers)
            {
                if (rowObject.contains(header))
                {
                    QStandardItem* item = new QStandardItem(rowObject[header].toString());
                    rowItems.append(item);
                }
            }
            model->appendRow(rowItems);
        }

        model->setHorizontalHeaderLabels(headers);
    }

    return model;
}
