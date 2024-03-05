#include "p_authorization.h"

const PacketTypes P_Authorization::packettype = PacketTypes::P_Authorization;
Window_Admin* P_Authorization::adminW;
QString P_Authorization::nickname;

void P_Authorization::openMainWindow(User user)
{
    WindowTracker::activeWindow->close();

    if (user.role == Roles::Admin)
    {
        adminW = new Window_Admin(user.fullName); //TODO: передавать в конструктор формы роль и тут же в зависимости от роли открывать соответствующую форму
        adminW->show();
    }
}

User P_Authorization::getUser()
{
    Roles role;
    recv(NetworkClient::serverSocket, reinterpret_cast<char*>(&role), sizeof(role), 0);
    QString fullName = NetworkClient::getMessageFromServer();

    return {role, fullName};
}

void P_Authorization::sendData(QString login, QString password)
{
    setActualNickname(login);
    NetworkClient::sendToServer(&packettype, sizeof(PacketTypes));
    NetworkClient::sendToServer(login);
    NetworkClient::sendToServer(password);
}

void P_Authorization::setActualNickname(QString actualNickname)
{
    nickname = actualNickname;
}

QString& P_Authorization::getActualNickname()
{
    return nickname;
}
