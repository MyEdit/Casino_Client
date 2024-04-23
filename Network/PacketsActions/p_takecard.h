#ifndef P_TAKECARD_H
#define P_TAKECARD_H

#include "Games/card.h"
#include "Network/networkclient.h"

class P_TakeCard
{
public:
    static QSharedPointer<Card> takeCard();
    static QString takeCardAnotherPlayer();
    static void renderTakeCard(QSharedPointer<Card> card);
    static void renderTakeCardAnotherPlayer(QString nicname);
};

#endif // P_TAKECARD_H
