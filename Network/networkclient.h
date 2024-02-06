#ifndef NETWORKCLIENT_H
#define NETWORKCLIENT_H

#include <winsock2.h> // [Для себя] Для работы нужно добавить LIBS += -lws2_32 в .pro файл
#include <Utils/Message.h>
#include <thread>
#include <Constants.h>
#include <QSharedPointer>
#include <QObject>
#include <Network/PacketTypes.h>
#include <Network/PacketsActions/p_authorization.h>
#include <Network/clienthandler.h>

class NetworkClient : public QObject
{
    Q_OBJECT

private:
    SOCKADDR_IN serverAddress;

    void configuration();
    void packetHandler(PacketTypes packettype);

public:
    static SOCKET serverSocket;

    bool init();
    bool connectToServer();
    static void sendToServer(QString message);

    template<typename T>
    static void sendToServer(const T data, int size)
    {
        send(serverSocket, reinterpret_cast<const char*>(data), size, 0);
    }
};

#endif // NETWORKCLIENT_H
