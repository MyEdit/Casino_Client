#include "p_reconnection.h"

QSharedPointer<Reconnecting> P_Reconnection::reconnecting;

void P_Reconnection::viewReconnecting()
{
    reconnecting = QSharedPointer<Reconnecting>(new Reconnecting());
    reconnecting->setAlertProperties(WindowTracker::activeWindow);
}

void P_Reconnection::stopReconnecting()
{
    reconnecting->close();
    reconnecting.clear();
}
