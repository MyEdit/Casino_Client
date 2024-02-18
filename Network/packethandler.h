#ifndef CLIENTHANDLER_H
#define CLIENTHANDLER_H

#include <QThread>
#include "Network/PacketTypes.h"
#include "Network/PacketsActions/p_authorization.h"
#include "Network/PacketsActions/p_sendmodel.h"
#include "Network/PacketsActions/p_query.h"
#include "Network/PacketsActions/p_notification.h"

class NetworkClient;

class PacketHandler : public QThread
{
    Q_OBJECT

private:
    void run() override;
    void clientHandler();
    void packetHandler(PacketTypes packettype);
    void tryReconnectToServer();

signals:
    void signalOpenForm();
    void signalSetModel(ModelData);
    void signalSetQueryModel(QueryData*);
    void signalViewNotification(QString);
};

#endif // CLIENTHANDLER_H
