#ifndef CLIENTHANDLER_H
#define CLIENTHANDLER_H

#include <QThread>
#include "GUI/Notification/notification.h"
#include "Network/PacketTypes.h"
#include "Network/PacketsActions/p_authorization.h"
#include "Network/PacketsActions/p_sendmodel.h"
#include "Network/PacketsActions/p_query.h"
#include "Network/PacketsActions/p_notification.h"
#include "Network/PacketsActions/p_sendtables.h"
#include "Users/user.h"

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
    void signalOpenForm(QSharedPointer<User> user);
    void signalSetModel(ModelData);
    void signalSetQueryModel(QueryData*);
    void signalViewNotification(QPair<TypeMessage, QString>);
    void signalReconnecting();
    void signalFinishReconnecting();
    void signalSetTables();
};

#endif // CLIENTHANDLER_H
