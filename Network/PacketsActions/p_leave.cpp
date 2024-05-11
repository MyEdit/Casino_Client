#include "p_leave.h"


void P_Leave::leave()
{
    P_Authorization::getPlayer()->getGame()->getGUI()->close();
    P_Authorization::getPlayer()->setGame(nullptr);
}
