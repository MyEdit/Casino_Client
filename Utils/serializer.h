#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <QStandardItemModel>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

class Serializer
{

public:
    static QSharedPointer<QStandardItemModel> deserializationDataModel(QByteArray receivedData);
};

#endif // SERIALIZER_H
