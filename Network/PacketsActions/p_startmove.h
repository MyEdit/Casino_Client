#ifndef P_STARTMOVE_H
#define P_STARTMOVE_H

#include "Network/networkclient.h"

class P_StartMove
{
public:
    static const QString getMove();
    static void startMove(const QString &nickname);
};

#endif // P_STARTMOVE_H
