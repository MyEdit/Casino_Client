#include "p_authorization.h"

const PacketTypes P_Authorization::packettype = PacketTypes::P_Authorization;
Window_Admin* P_Authorization::adminW;
Window_Player* P_Authorization::playerW;
QString P_Authorization::nickname;

void P_Authorization::openMainWindow(UserData user)
{
    WindowTracker::activeWindow->close();

    if(user.role == Roles::User)
    {
        playerW = new Window_Player(user.fullName);
        playerW->show();
        return;
    }

    if (user.role != Roles::None)
    {
        adminW = new Window_Admin(user.role, user.fullName);
        adminW->show();
    }
}

UserData P_Authorization::getUser()
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
