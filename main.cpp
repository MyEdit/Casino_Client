#include <QApplication>
#include "Gui/Notification/notification.h"
#include "Gui/window_auth.h"
#include "Network/networkclient.h"

NetworkClient network;
QWidget* WindowTracker::activeWindow;

void initIP()
{
    QString filename = "conf.txt";
    QFile file(filename);

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        Message::logError("отсутстувует conf.txt");
        exit(-1);
    }

    QTextStream in(&file);
    while(!in.atEnd())
    {
        NetworkClient::ADDRESS = in.readLine();
        return;
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    initIP();

    Window_Auth w;
    WindowTracker::activeWindow = &w;
    w.show();
    P_Authorization::setWindowAuth(&w);

    if (!network.init())
        Notification::showNotification(TypeMessage::Error, "Произошла ошибка при инициилизации сетевого кода");

    if (!network.start())
        Notification::showNotification(TypeMessage::Error, "Произошла ошибка при подключении к серверу");

    return a.exec();
}
