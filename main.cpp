#include "GUI/window_auth.h"
#include <QApplication>
#include "Network/networkclient.h"

NetworkClient network;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    if (!network.init())
    {
        return 1; //тут можно вызывать уведомление об ошибке сразу в гуи
    }

    if (!network.connectToServer())
    {
        return 1; //тут можно вызывать уведомление об ошибке сразу в гуи
    }

    Window_Auth w;
    w.show();
    return a.exec();
}
