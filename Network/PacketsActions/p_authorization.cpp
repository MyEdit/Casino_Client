#include "p_authorization.h"

void P_Authorization::openMainWindow()
{
    Message::logInfo("Open form...");

    QWidget* currentForm = QApplication::activeWindow();
    currentForm->close();

    Window_Admin* w = new Window_Admin;
    w->show();
}
