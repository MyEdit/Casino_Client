#include "p_startmove.h"

void P_StartMove::startMove()
{
    P_Authorization::getPlayer()->getTableGUI()->blocingInterface(true);
}
