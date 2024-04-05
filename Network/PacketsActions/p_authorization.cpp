#include "p_authorization.h"

const PacketTypes P_Authorization::packettype = PacketTypes::P_Authorization;
Window_Admin* P_Authorization::adminW;
Window_Player* P_Authorization::playerW;
QSharedPointer<User> P_Authorization::user;

void P_Authorization::openMainWindow(QSharedPointer<User> user)
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

QSharedPointer<User> P_Authorization::getUser()
{
    Roles role;
    int sizeByteUser;
    QByteArray byteUser;

    recv(NetworkClient::serverSocket, reinterpret_cast<char*>(&role), sizeof(role), 0);
    recv(NetworkClient::serverSocket, reinterpret_cast<char*>(&sizeByteUser), sizeof(int), 0);
    byteUser.resize(sizeByteUser);
    recv(NetworkClient::serverSocket, byteUser.data(), sizeByteUser, 0);
    QSharedPointer<User> user;
    if(role == Roles::User)
        user = QSharedPointer<Player>::create(byteUser);
    else
        user = QSharedPointer<StuffUser>::create(byteUser);

    return user;
}

void P_Authorization::sendData(QString login, QString password)
{
    NetworkClient::sendToServer(&packettype, sizeof(PacketTypes));
    NetworkClient::sendToServer(login);
    NetworkClient::sendToServer(password);
}

void P_Authorization::setActualUser(QSharedPointer<User> newUser)
{
    user = newUser;
}

QSharedPointer<User> P_Authorization::getActualUser()
{
    return user;
}
