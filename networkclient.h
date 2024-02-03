#ifndef NETWORKCLIENT_H
#define NETWORKCLIENT_H

#include <winsock2.h> // [��� ����] ��� ������ ����� �������� LIBS += -lws2_32 � .pro ����
#include <Message.h>
#include <thread>
#include <Constants.h>
#include <QSharedPointer>
#include <PacketTypes.h>

class NetworkClient
{
private:
    static SOCKET serverSocket;
    SOCKADDR_IN serverAddress;

    void configuration();
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
