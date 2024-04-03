#include "networkclient.h"

SOCKET NetworkClient::serverSocket = INVALID_SOCKET;
SOCKADDR_IN NetworkClient::serverAddress;
PacketHandler* NetworkClient::packetHandler;

//Инициилизация
bool NetworkClient::init()
{
    WSAData wsaData;
    WORD DLLVersion = MAKEWORD(2, 1); //Запрашиваемая версия либы winsock
    if (WSAStartup(DLLVersion, &wsaData) != 0) //Загрузка библиотеки winsock
    {
        Message::logError("WSA library failed to load!");
        return false;
    }
    configuration();
    return true;
}

//Заполнение информации об адресе сокета
void NetworkClient::configuration()
{
    serverAddress.sin_addr.s_addr = inet_addr(ADDRESS);
    serverAddress.sin_port = htons(PORT);
    serverAddress.sin_family = AF_INET; //Интернет протокол
    serverSocket = socket(AF_INET, SOCK_STREAM, 0); //Создаю сокет
}

//Коннект к серверу
bool NetworkClient::connectToServer()
{
    if (!serverAddress.sin_port)
    {
        Message::logError("The socket is not configured");
        return false;
    }

    if (serverSocket == INVALID_SOCKET)
    {
        configuration();
    }

    if (_WINSOCKAPI_::connect(serverSocket, (SOCKADDR*)&serverAddress, sizeof(serverAddress)) != 0) //Коннект к серверу
    {
        Message::logError("Failed connect to server!");
        return false;
    }

    return true;
}

bool NetworkClient::start()
{
    if (!connectToServer())
        return false;

    qRegisterMetaType<ModelData>("ModelData");
    qRegisterMetaType<ModelData>("QueryData");
    qRegisterMetaType<Roles>("Roles");
    qRegisterMetaType<QSharedPointer<ObjectUser>>("QSharedPointer<ObjectUser>");
    qRegisterMetaType<QPair<TypeMessage, QString>>("QPair<TypeMessage, QString>");

    packetHandler = new PacketHandler();

    //Коннекты с сигналами из потока обработчика пакетов
    QObject::connect(packetHandler, &PacketHandler::signalOpenForm, this, &P_Authorization::openMainWindow);
    QObject::connect(packetHandler, &PacketHandler::signalSetModel, this, &P_SendModel::setModel);
    QObject::connect(packetHandler, &PacketHandler::signalViewNotification, this, &NotificationUtil::viewNotification);
    QObject::connect(packetHandler, &PacketHandler::signalReconnecting, this, &P_Reconnection::viewReconnecting);
    QObject::connect(packetHandler, &PacketHandler::signalFinishReconnecting, this, &P_Reconnection::stopReconnecting);

    packetHandler->start();
    return true;
}

//Отправка пакета серверу
void NetworkClient::sendToServer(QString message)
{
    int message_size = message.toUtf8().size();
    send(serverSocket, reinterpret_cast<const char*>(&message_size), sizeof(int), 0);
    send(serverSocket, reinterpret_cast<const char*>(message.toUtf8().constData()), message_size, 0);
}

//Парс и получение пакета от сервера с неизвестной длинной
QString NetworkClient::getMessageFromServer()
{
    int size;
    recv(serverSocket, reinterpret_cast<char*>(&size), sizeof(int), 0);
    QByteArray buffer(size, 0);
    recv(serverSocket, buffer.data(), size, 0);
    return QString(buffer);
}

void NetworkClient::onServerDisconnected()
{
    Message::logError("Сonnection to server was lost or an error occurred");
    closesocket(serverSocket);
    serverSocket = INVALID_SOCKET;
}
