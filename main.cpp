#include <QApplication>
#include "Gui/Notification/notification.h"
#include "Gui/window_auth.h"
#include "Network/networkclient.h"

NetworkClient network;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Notification* notification = new Notification();
    Window_Auth w;
    WindowTracker::activeWindow = &w;
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
