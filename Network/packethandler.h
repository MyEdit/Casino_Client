﻿#ifndef CLIENTHANDLER_H
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
#include "Users/user.h"

class NetworkClient;
class Table;

class PacketHandler : public QThread
{
    Q_OBJECT

private:
    void run() override;
    void clientHandler();
    void packetHandler(const PacketTypes packettype);
    void tryReconnectToServer();

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
    void signalTakeCard(const QSharedPointer<Card>);
    void signalTakeCardAnotherPlayer(const QString);
    void signalStartMove(const QString);
};

#endif // CLIENTHANDLER_H
