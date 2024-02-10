#ifndef CLIENTHANDLER_H
#define CLIENTHANDLER_H

#include <QThread>
#include <Network/PacketTypes.h>
#include <Network/PacketsActions/p_authorization.h>
#include <Network/PacketsActions/p_sendmodel.h>

class PacketHandler : public QThread
{
    Q_OBJECT

private:
    void run() override;
    void clientHandler();
    void packetHandler(PacketTypes packettype);

signals:
    void signalOpenForm();
    void signalSetModelAllUsers(QStandardItemModel* model);
};

#endif // CLIENTHANDLER_H
