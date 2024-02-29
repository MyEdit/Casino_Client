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
#include "Network/PacketsActions/p_reconnecting.h"

class PacketHandler;

class NetworkClient : public QObject
{
    Q_OBJECT

private:
    static SOCKADDR_IN serverAddress;

    static void configuration();
    static bool connectToServer();

public:
    static SOCKET serverSocket;
    static PacketHandler* packetHandler;

    bool init();
    bool start();
    static void sendToServer(QString message);
    static QString getMessageFromServer();
    static void onServerDisconnected();

    template<typename T>
    static void sendToServer(const T data, const int size)
    {
        send(serverSocket, reinterpret_cast<const char*>(data), size, 0);
    }

    friend class PacketHandler;
};

#endif // NETWORKCLIENT_H
