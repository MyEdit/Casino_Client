#ifndef P_STARTMOVE_H
#define P_STARTMOVE_H

#include "Network/networkclient.h"

class P_StartMove
{
public:
    static QString getMove();
    static void startMove(QString nickname);
};

#endif // P_STARTMOVE_H
