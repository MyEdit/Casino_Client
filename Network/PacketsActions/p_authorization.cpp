#include "p_authorization.h"

Window_Admin* P_Authorization::adminW;

void P_Authorization::openMainWindow()
{
    qApp->activeWindow()->close();
    adminW = new Window_Admin;
    adminW->show();
}
