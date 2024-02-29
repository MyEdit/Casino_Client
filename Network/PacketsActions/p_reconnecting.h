#ifndef P_RECONNECTING_H
#define P_RECONNECTING_H

#include "Gui/reconnecting.h"
#include "Utils/windowtracker.h"

class P_Reconnecting
{
    static Reconnecting* reconnecting;
public:
    static void viewReconnecting();
    static void stopReconnecting();
};

#endif // P_RECONNECTING_H
