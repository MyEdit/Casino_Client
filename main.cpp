#include "window_auth.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Window_Auth w;
    w.show();
    return a.exec();
}
