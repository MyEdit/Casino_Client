#include "p_authorization.h"

Window_Admin* P_Authorization::adminW;

void P_Authorization::openMainWindow(Roles role)
{
    qApp->activeWindow()->close();
    adminW = new Window_Admin; //TODO: передавать в конструктор формы роль и тут же в зависимости от роли открывать соответствующую форму
    adminW->show();
}

Roles P_Authorization::getRole()
{
    Roles role;
    recv(NetworkClient::serverSocket, reinterpret_cast<char*>(&role), sizeof(role), 0);
    return role;
}
