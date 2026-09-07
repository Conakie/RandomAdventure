
#ifndef KIIYUO_LOCALE_CLASS_H
#define KIIYUO_LOCALE_CLASS_H

#include <vector>
#include "Room.h"
#include "Random.h"
#include "PlacesID.h"
#include "Loot.h"
#include "EncounterType.h"
#include "Items.h"

class Localez
{
private:
    using EncType = Creatures::Encounter::EncounterType;
    using Item = Items::ItemName;
public:
    Localez() = default;

    void generateLocale();
    Creatures::Encounter::EncounterType generateEncounter();
    void reset();
    bool goToNextRoom();
    bool goToPreviousRoom();
    void printCurrentRoom() const;
    void removeCurrentRoomEncounter();
    std::pair<Item, int> getLootFromCurrentRoom();
    void deleteLocale();

    void setCurrentRoomIndex(int index) { m_currentRoom = index; }

    bool isEmpty() const { return m_rooms.empty(); }
    size_t size() const { return m_rooms.size(); }
    size_t getCurrentRoomIndex() const { return m_currentRoom; }
    EncType getCurrentRoomEncounterType() const;
    PlacesID getPlaceID() const { return m_localeType; }
private:
    //void generateRoom();
    void generateTreasureRoom();
    EncType generateDungeonEncounter();
    EncType generateVillageEncounter();
    EncType generateCaveEncounter();
    EncType generateForestEncounter();
    EncType generateStrongholdEncounter();
    EncType generateAnyEncounter();
    void printDungeonRoom() const;
    void printVillageRoom() const;
    void printCaveRoom() const;
    void printForestRoom() const;
    void printStrongholdRoom() const;

    int m_currentRoom{ 0 };
    int m_localeVariant{ 0 };
    std::vector<Room> m_rooms;
    PlacesID m_localeType{ PlacesID::unknown };
};

#endif // !KIIYUO_LOCALE_CLASS_H