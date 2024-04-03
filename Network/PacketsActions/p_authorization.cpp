#include "p_authorization.h"

const PacketTypes P_Authorization::packettype = PacketTypes::P_Authorization;
Window_Admin* P_Authorization::adminW;
Window_Player* P_Authorization::playerW;
QSharedPointer<ObjectUser> P_Authorization::actualUser;

void P_Authorization::openMainWindow(QSharedPointer<ObjectUser> user)
{
    WindowTracker::activeWindow->close();

    setActualUser(user);

    if(user->getRole() == Roles::User)
    {
        playerW = new Window_Player();
        playerW->show();
        return;
    }

    if (user->getRole()  != Roles::None)
    {
        adminW = new Window_Admin();
        adminW->show();
    }
}

QSharedPointer<ObjectUser> P_Authorization::getUser()
{
    Roles role;
    int sizeByteUser;
    QByteArray byteUser;

    recv(NetworkClient::serverSocket, reinterpret_cast<char*>(&role), sizeof(role), 0);
    recv(NetworkClient::serverSocket, reinterpret_cast<char*>(&sizeByteUser), sizeof(int), 0);
    byteUser.resize(sizeByteUser);
    recv(NetworkClient::serverSocket, byteUser.data(), sizeByteUser, 0);

    QSharedPointer<ObjectUser> user;
    if(role == Roles::User)
        user = ObjectPlayer::deserializeUser(byteUser);
    else
        user = ObjectStuffUser::deserializeUser(byteUser);

    return user;
}

void P_Authorization::sendData(QString login, QString password)
{
    NetworkClient::sendToServer(&packettype, sizeof(PacketTypes));
    NetworkClient::sendToServer(login);
    NetworkClient::sendToServer(password);
}

void P_Authorization::setActualUser(QSharedPointer<ObjectUser> user)
{
    actualUser = user;
}

QSharedPointer<ObjectUser> P_Authorization::getActualUser()
{
    return actualUser;
}
