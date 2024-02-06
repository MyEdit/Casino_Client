#include "p_authorization.h"

void P_Authorization::openMainWindow()
{
    QWidget* currentForm = QApplication::activeWindow();
    currentForm->close();

    Window_Admin* w = new Window_Admin;
    w->show();

    //Запрашиваю у сервера модель с данными "Пользователи"
    PacketTypes packettype = PacketTypes::P_SendModel;
    ModelTypes modeltype = ModelTypes::Users;
    NetworkClient::sendToServer(&packettype, sizeof(PacketTypes));
    NetworkClient::sendToServer(&modeltype, sizeof(ModelTypes));
}
