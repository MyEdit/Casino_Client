#include "p_authorization.h"

Window_Admin* P_Authorization::adminW;

void P_Authorization::openMainWindow()
{
    QWidget* currentForm = QApplication::activeWindow();
    currentForm->close();

    adminW = new Window_Admin;
    adminW->show();
}
