#ifndef NETWORKCLIENT_H
#define NETWORKCLIENT_H

#include <winsock2.h> // [Для себя] Для работы нужно добавить LIBS += -lws2_32 в .pro файл
#include <Utils/Message.h>
#include <thread>
#include <Constants.h>
#include <QSharedPointer>
#include <Network/PacketTypes.h>
#include <Network/PacketsActions/p_authorization.h>

class NetworkClient
{
private:
    static SOCKET serverSocket;
    SOCKADDR_IN serverAddress;

    void configuration();
    static void packetHandler(PacketTypes packettype);
    static void clientHandler();

public:
    bool init();
    bool connectToServer();
    static void sendToServer(QString message);

    template<typename T>
    static void sendToServer(const T data, int size)
    {
        send(serverSocket, (char*)data, size, 0);
    }
};

#endif // NETWORKCLIENT_H
