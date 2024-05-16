#include "p_authorization.h"

const PacketTypes P_Authorization::packettype = PacketTypes::P_Authorization;
Window_Admin* P_Authorization::adminW;
Window_Player* P_Authorization::playerW;
QSharedPointer<User> P_Authorization::user;
QSharedPointer<Player> P_Authorization::player;
QSharedPointer<StuffUser> P_Authorization::stuffUser;
QMutex P_Authorization::accessMutex;
Window_Auth* P_Authorization::windowAuth;

void P_Authorization::setWindowAuth(Window_Auth *value)
{
    windowAuth = value;
}

void P_Authorization::openMainWindow(QSharedPointer<User> user)
{
    windowAuth->close();
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
    QMutexLocker locker(&accessMutex);
    Roles role = NetworkClient::getMessageFromServer<Roles>();
    int sizeByteUser = NetworkClient::getMessageFromServer<int>();
    QByteArray byteUser = NetworkClient::getMessageFromServer<QByteArray>(sizeByteUser);

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

void P_Authorization::sendData(const QString& login, const QString& password)
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
    QMutexLocker locker(&accessMutex);
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

void P_Authorization::showAuthWindow()
{
    WindowTracker::activeWindow->close();
    WindowTracker::activeWindow = nullptr;
    P_Authorization::adminW = nullptr;
    P_Authorization::playerW = nullptr;

    windowAuth = new Window_Auth();
    windowAuth->show();
    WindowTracker::activeWindow = windowAuth;
}
