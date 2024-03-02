#include "p_authorization.h"

const PacketTypes P_Authorization::packettype = PacketTypes::P_Authorization;
Window_Admin* P_Authorization::adminW;
QString P_Authorization::nickname;

void P_Authorization::openMainWindow(Roles role)
{
    qApp->activeWindow()->close();

    if (role == Roles::Admin)
    {
        adminW = new Window_Admin; //TODO: передавать в конструктор формы роль и тут же в зависимости от роли открывать соответствующую форму
        adminW->show();
    }
}

Roles P_Authorization::getRole()
{
    Roles role;
    recv(NetworkClient::serverSocket, reinterpret_cast<char*>(&role), sizeof(role), 0);
    return role;
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
