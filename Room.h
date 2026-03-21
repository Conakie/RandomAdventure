
#ifndef KIIYUO_ROOM_STRUCT_H
#define KIIYUO_ROOM_STRUCT_H

#include "EncounterType.h"
#include "PlacesID.h"
#include "Loot.h"

struct Room
{
    using EncType = Creatures::Encounter::EncounterType;
    int m_roomID{ -1 };
    EncType m_encounterOfTheRoom{ EncType::none };
    bool m_hasBeenOpened{ false };
    bool m_hasBeenEntered{ false };
    LightAmount m_lightLevel{ LightAmount::unknown };
    LootAmount m_lootAmount{ LootAmount::unknown };

    void reset();
};

#endif // !KIIYUO_ROOM_STRUCT_H
