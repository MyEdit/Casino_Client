#include "p_authorization.h"

const PacketTypes P_Authorization::packettype = PacketTypes::P_Authorization;
Window_Admin* P_Authorization::adminW;
Window_Player* P_Authorization::playerW;
QSharedPointer<User> P_Authorization::user;
QSharedPointer<Player> P_Authorization::player;
QSharedPointer<StuffUser> P_Authorization::stuffUser;
QMutex P_Authorization::accessMutex;

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

    if (user->getRole()  == Roles::Admin || user->getRole()  == Roles::TableManager)
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
    {
        player = QSharedPointer<Player>::create(byteUser);
        user = player;
    }
    else
    {
        stuffUser = QSharedPointer<StuffUser>::create(byteUser);
        user = stuffUser;
    }

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
    QMutexLocker locker(&accessMutex);
    user = newUser;
}

QSharedPointer<User> P_Authorization::getActualUser()
{
    return user;
}

QSharedPointer<Player> P_Authorization::getPlayer()
{
    QMutexLocker locker(&accessMutex);
    return player;
}

QSharedPointer<StuffUser> P_Authorization::getStuffuser()
{
    QMutexLocker locker(&accessMutex);
    return stuffUser;
}
