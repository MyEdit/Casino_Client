#include "p_gamepacket.h"

void P_GamePacket::onGamePacketReceived()
{
    P_Authorization::getPlayer()->getGame()->onGamePacketReceived();
}
