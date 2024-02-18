﻿#include <QApplication>
#include "GUI/notification.h"
#include "GUI/window_auth.h"
#include "Network/networkclient.h"

NetworkClient network;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Notification* notification = new Notification();

    Window_Auth w;
    w.show();

    if (!network.init())
    {
        notification->setAlertProperties(TypeMessage::Error, "Произошла ошибка при инициилизации сетевого кода", &w);
    }

    if (!network.start())
    {
        notification->setAlertProperties(TypeMessage::Error, "Произошла ошибка при подключении к серверу", &w);
    }

    return a.exec();
}
