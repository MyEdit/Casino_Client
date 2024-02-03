#include "window_auth.h"
#include <QApplication>
#include <networkclient.h>

NetworkClient network;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    if (!network.init())
    {
        return 1; //��� ����� �������� ����������� �� ������ ����� � ���
    }

    if (!network.connectToServer())
    {
        return 1; //��� ����� �������� ����������� �� ������ ����� � ���
    }

    Window_Auth w;
    w.show();
    return a.exec();
}
