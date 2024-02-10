#include "p_authorization.h"

Window_Admin* P_Authorization::adminW;

void P_Authorization::openMainWindow()
{
    QWidget* currentForm = QApplication::activeWindow();
    currentForm->close();

    adminW = new Window_Admin;
    adminW->show();

    //Запрашиваю у сервера модель с данными "Пользователи"
    PacketTypes packettype = PacketTypes::P_SendModel;
    ModelTypes modeltype = ModelTypes::Users;
    NetworkClient::sendToServer(&packettype, sizeof(PacketTypes));
    NetworkClient::sendToServer(&modeltype, sizeof(ModelTypes));
}

void P_Authorization::setModelAllUsers(QStandardItemModel* model)
{
    if(adminW)
        adminW->setModel_AllUsersTab(model);
}
