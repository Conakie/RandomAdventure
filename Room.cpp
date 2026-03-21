
#include "Room.h"

void Room::reset()
{
    m_roomID = -1;
    m_encounterOfTheRoom = EncType::none;
    m_hasBeenOpened = false;
    m_hasBeenEntered = false;
    m_lightLevel = LightAmount::unknown;
    m_lootAmount = LootAmount::unknown;
}