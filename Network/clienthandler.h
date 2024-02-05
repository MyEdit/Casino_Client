#ifndef CLIENTHANDLER_H
#define CLIENTHANDLER_H

#include <QThread>
#include <Network/PacketTypes.h>
#include <Network/PacketsActions/p_authorization.h>

class ClientHandler : public QThread
{
    Q_OBJECT

protected:
    void run() override;

signals:
    void signalPacketHandler(PacketTypes);
};

#endif // CLIENTHANDLER_H
