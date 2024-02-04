#include "networkclient.h"

SOCKET NetworkClient::serverSocket = INVALID_SOCKET;

//�������������
bool NetworkClient::init()
{
    WSAData wsaData;
    WORD DLLVersion = MAKEWORD(2, 1); //������������� ������ ���� winsock
    if (WSAStartup(DLLVersion, &wsaData) != 0) //�������� ���������� winsock
    {
        Message::logError("WSA library failed to load!");
        return false;
    }
    configuration();
    return true;
}

//���������� ���������� �� ������ ������
void NetworkClient::configuration()
{
    serverAddress.sin_addr.s_addr = inet_addr(ADDRESS);
    serverAddress.sin_port = htons(PORT);
    serverAddress.sin_family = AF_INET; //�������� ��������
    serverSocket = socket(AF_INET, SOCK_STREAM, 0); //������ �����
}

//������� � �������
bool NetworkClient::connectToServer()
{
    if (!serverAddress.sin_port)
    {
        Message::logError("The socket is not configured");
        return false;
    }

    if (connect(serverSocket, (SOCKADDR*)&serverAddress, sizeof(serverAddress)) != 0) //������� � �������
    {
        Message::logError("Failed connect to server!");
        return false;
    }

    std::thread handler(clientHandler);
    handler.detach();
    Message::logInfo("Connection successful!");
    return true;
}

//�� ���� ������������� ����� �����������
void NetworkClient::packetHandler(PacketTypes packettype)
{
    switch(packettype)
    {
        case(PacketTypes::P_Authorization):
        {
            P_Authorization::openMainWindow();
            break;
        }
        case(PacketTypes::P_Notification):
        {
            break;
        }
        case(PacketTypes::P_DeleteTable):
        {
            break;
        }
        case(PacketTypes::P_AddTable):
        {
            break;
        }
        case(PacketTypes::P_ConnectPlayerToTable):
        {
            break;
        }
        case(PacketTypes::P_SendModel):
        {
            break;
        }
        case(PacketTypes::P_SendTables):
        {
            break;
        }
        default:
        {
            Message::logWarn("Client send unknown packettype");
            break;
        }
    }
}

//��������� ���� �������� ��������� �� �������
void NetworkClient::clientHandler()
{
    PacketTypes packettype;
    while(true)
    {
        if (recv(serverSocket, (char*)&packettype, sizeof(PacketTypes), 0) <= 0)
        {
            Message::logError("Impossible...");
        }
        packetHandler(packettype);
    }
}

//�������� ������ �������
void NetworkClient::sendToServer(QString message)
{
    int message_size = message.size();
    send(serverSocket, (char*)&message_size, sizeof(int), 0);
    send(serverSocket, (char*)message.toUtf8().constData(), message_size, 0);
}
