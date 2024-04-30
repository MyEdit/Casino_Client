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
#include "Network/PacketsActions/p_reconnection.h"
#include "Network/PacketsActions/p_takecard.h"
#include "Network/PacketsActions/p_startmove.h"

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

    bool init() const;
    bool start() const;
    static void sendToServer(const QString& message);
    static const QString getMessageFromServer();
    static void onServerDisconnected();

    template<typename T>
    static void sendToServer(const T data, const int size)
    {
        send(serverSocket, reinterpret_cast<const char*>(data), size, 0);
    }

    template<typename T>
    static T getMessageFromServer()
    {
        T returnData{};
        recv(serverSocket, reinterpret_cast<char*>(&returnData), sizeof(T), 0);
        return returnData;
    }

    template<typename T>
    static typename std::enable_if<std::is_same<T, QByteArray>::value, T>::type
    getMessageFromServer(int size)
    {
        QByteArray returnData(size, 0);
        recv(serverSocket, returnData.data(), size, 0);
        return returnData;
    }

    friend class PacketHandler;
};

#endif // NETWORKCLIENT_H
