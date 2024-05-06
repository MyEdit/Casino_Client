#ifndef BLACKJACKGAMEPACKETS_H
#define BLACKJACKGAMEPACKETS_H

enum class GamePackets
{
    P_TakeCard,
    P_TakeCardAnotherPlayer,
    P_PassMove,
    P_StartMove,
    P_Win,
    P_Lose
};

#endif // BLACKJACKGAMEPACKETS_H
