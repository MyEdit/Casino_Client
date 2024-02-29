#include "p_reconnecting.h"

Reconnecting* P_Reconnecting::reconnecting;

void P_Reconnecting::viewReconnecting()
{
    reconnecting = new Reconnecting();
    reconnecting->setAlertProperties(WindowTracker::activeWindow);
}

void P_Reconnecting::stopReconnecting()
{
    reconnecting->close();
    delete reconnecting;
}
