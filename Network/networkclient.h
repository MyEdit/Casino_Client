#ifndef NETWORKCLIENT_H
#define NETWORKCLIENT_H

#include <winsock2.h> // [для себя] для работы нужно добавить LIBS += -lws2_32 в .pro файл
#include "Utils/Message.h"
#include <thread>
#include "Constants.h"
#include <QSharedPointer>
#include <QObject>
#include "Network/PacketTypes.h"
#include "Network/PacketsActions/p_authorization.h"
#include "Network/PacketsActions/p_sendmodel.h"
#include "Network/packethandler.h"

class PacketHandler;

class NetworkClient : public QObject
{
    Q_OBJECT

private:
    SOCKADDR_IN serverAddress;

    void configuration();

public:
    static SOCKET serverSocket;
    static PacketHandler* packetHandler;

    bool init();
    bool connectToServer();
    static void sendToServer(QString message);
    static QString getMessageFromServer();

    template<typename T>
    static void sendToServer(const T data, const int size)
    {
        send(serverSocket, reinterpret_cast<const char*>(data), size, 0);
    }
};

#endif // NETWORKCLIENT_H
