
#ifndef KIIYUO_LOCALE_CLASS_H
#define KIIYUO_LOCALE_CLASS_H

#include <vector>
#include "Room.h"
#include "Random.h"
#include "PlacesID.h"
#include "Loot.h"
#include "EncounterType.h"

class Locale
{
private:
    using EncType = Creatures::Encounter::EncounterType;
public:
    Locale() = default;

    void generateLocale();
    Creatures::Encounter::EncounterType generateEncounter();
    void reset();
    void goToNextRoom();
    void goToPreviousRoom();

    bool isEmpty() const { return m_rooms.empty(); }
    size_t size() const { return m_rooms.size(); }
    size_t getCurrentRoomIndex() const { return m_currentRoom; }
    EncType getCurrentRoomEncounterType() const;
private:
    //void generateRoom();
    void generateTreasureRoom();
    EncType generateDungeonEncounter();
    EncType generateVillageEncounter();
    EncType generateCaveEncounter();
    EncType generateForestEncounter();
    EncType generateStrongholdEncounter();
    EncType generateAnyEncounter();

    int m_currentRoom{ 0 };
    int m_localeVariant{ 0 };
    std::vector<Room> m_rooms;
    PlacesID m_localeType{ PlacesID::unknown };
};

#endif // !KIIYUO_LOCALE_CLASS_H