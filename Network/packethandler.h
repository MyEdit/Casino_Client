#ifndef CLIENTHANDLER_H
#define CLIENTHANDLER_H

#include <QThread>
#include "Gui/Notification/notification.h"
#include "Network/PacketTypes.h"
#include "Network/PacketsActions/p_authorization.h"
#include "Network/PacketsActions/p_sendmodel.h"
#include "Network/PacketsActions/p_query.h"
#include "Network/PacketsActions/p_notification.h"
#include "Network/PacketsActions/p_sendtables.h"
#include "Network/PacketsActions/p_connectplayertotable.h"
#include "Network/PacketsActions/p_updategameprocessing.h"
#include "Network/PacketsActions/p_gamepacket.h"
#include "Network/PacketsActions/p_search.h"
#include "Network/PacketsActions/p_updatebalance.h"
#include "Network/PacketsActions/p_update.h"
#include "Users/user.h"

class NetworkClient;
class Table;
class Card;

class PacketHandler : public QThread
{
    Q_OBJECT
    QMap<PacketTypes, std::function<void()>> packetHandlerFunction;

private:
    PacketHandler();
    void run() override;
    void clientHandler();
    void packetHandler(const PacketTypes packettype);
    void tryReconnectToServer();
    void initPacketHandlerFunction();

signals:
    void signalOpenForm(QSharedPointer<User>);
    void signalSetModel(QSharedPointer<ModelData>);
    void signalSetQueryModel(QSharedPointer<QueryData>);
    void signalViewNotification(QPair<TypeMessage, const QString>);
    void signalReconnecting();
    void signalFinishReconnecting();
    void signalSetTables();
    void signalOpenGame(QSharedPointer<Table>);
    void signalUpdatePlayers(QSharedPointer<Table>);
    void signalUpdateGameProcessing(const QString);
    void signalResultSearch(QPair<ModelTypes, QString>);
    void signalUpdateBalance(double newBalance);
    void signalUpdateTable(const ModelTypes modelType);
};

#endif // CLIENTHANDLER_H
