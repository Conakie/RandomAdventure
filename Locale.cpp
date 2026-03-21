
#include <array>
#include <iostream>
#include "Locale.h"
#include "Random.h"
#include "EncounterType.h"
#include "Loot.h"
#include "PlacesID.h"

void Locale::generateLocale()
{
    // randomly selects a locale type and variant
    m_localeType = static_cast<PlacesID>(Random::get(0, 4));
    m_localeType = PlacesID::dungeon;

    switch (m_localeType)
    {
    case PlacesID::dungeon:
        m_localeVariant = Random::get(0, 4);
        break;
    case PlacesID::village:
        m_localeVariant = Random::get(0, 4);
        break;
    case PlacesID::cave:
        m_localeVariant = Random::get(0, 4);
        break;
    case PlacesID::forest:
        m_localeVariant = Random::get(0, 4);
        break;
    case PlacesID::stronghold:
        m_localeVariant = Random::get(0, 4);
        break;
    case PlacesID::unknown:
        m_localeVariant = 0;
        break;
    default:
        m_localeVariant = 0;
        break;
    }
    // generates a random number of rooms and fills them
    // with encounters, loot, a light lvl and a room description
    m_rooms.resize(static_cast<size_t>(Random::get(2, 20)));

    for (size_t index = 0; index < m_rooms.size() - 1; index++)
    {
        m_rooms[index].m_roomID = Random::get(01, 10);
        m_rooms[index].m_encounterOfTheRoom = generateEncounter();
        m_rooms[index].m_lootAmount = static_cast<LootAmount>(Random::get(0, 3));
        m_rooms[index].m_lightLevel = static_cast<LightAmount>(Random::get(1, 3));
    }
    generateTreasureRoom();
}

Creatures::Encounter::EncounterType Locale::generateEncounter()
{
    if (Random::get(0, 99) < 15)
        return Creatures::Encounter::EncounterType::none;
    // generates an encounter based on the locale type
    switch (m_localeType)
    {
    case PlacesID::dungeon:
        return generateDungeonEncounter();
    case PlacesID::village:
        return generateVillageEncounter();
    case PlacesID::cave:
        return generateCaveEncounter();
    case PlacesID::forest:
        return generateForestEncounter();
    case PlacesID::stronghold:
        return generateStrongholdEncounter();
    case PlacesID::unknown:
        return generateAnyEncounter();
    default:
        return generateAnyEncounter();
    }
}

void Locale::generateTreasureRoom()
{
    // sets the last room to be a treasure room. Always.
    size_t index = m_rooms.size() - 1;

    m_rooms[index].m_roomID = 0;
    m_rooms[index].m_encounterOfTheRoom = generateEncounter();
    m_rooms[index].m_lootAmount = LootAmount::treasure;
    m_rooms[index].m_lightLevel = static_cast<LightAmount>(Random::get(1, 3));
}

Creatures::Encounter::EncounterType Locale::generateDungeonEncounter()
{
    constexpr EncType encounterPool[27]{
            EncType::torturer, EncType::giant, EncType::elf, EncType::dwarf, EncType::prisoner,
            EncType::theRock, EncType::shota, EncType::zombie, EncType::skeleton, EncType::witch,
            EncType::ghost, EncType::yourself, EncType::stoneGolem, EncType::blurp,
            EncType::smallRat, EncType::rat, EncType::giantRat, EncType::enormousRat,
            EncType::colossalRat, EncType::colossalSpider, EncType::ratman, EncType::goblin,
            EncType::hobgoblin, EncType::orc, EncType::kobold, EncType::kockbold,
            EncType::cockblin,
    };
    return encounterPool[Random::get(0, 26)];
}

Creatures::Encounter::EncounterType Locale::generateVillageEncounter()
{
    constexpr EncType encounterPool[22]{
            EncType::guard, EncType::drunkGuy, EncType::soldier, EncType::torturer, EncType::giant,
            EncType::priest, EncType::elf, EncType::dwarf, EncType::prisoner, EncType::trader,
            EncType::bartender, EncType::bard, EncType::loli, EncType::shota, EncType::witch,
            EncType::ghost, EncType::theBeer, EncType::blurp, EncType::smallRat, EncType::rat,
            EncType::the104, EncType::crackman,
    };
    return encounterPool[Random::get(0, 21)];
}

Creatures::Encounter::EncounterType Locale::generateCaveEncounter()
{
    constexpr EncType encounterPool[28]{
            EncType::torturer, EncType::giant, EncType::elf, EncType::dwarf, EncType::prisoner,
            EncType::theRock, EncType::shota, EncType::zombie, EncType::skeleton, EncType::witch,
            EncType::ghost, EncType::yourself, EncType::stoneGolem, EncType::blurp,
            EncType::smallRat, EncType::rat, EncType::giantRat, EncType::enormousRat,
            EncType::colossalRat, EncType::colossalSpider, EncType::ratman, EncType::goblin,
            EncType::hobgoblin, EncType::orc, EncType::kobold, EncType::kockbold,
            EncType::cockblin, EncType::bugBox,
    };
    return encounterPool[Random::get(0, 27)];
}

Creatures::Encounter::EncounterType Locale::generateForestEncounter()
{
    constexpr EncType encounterPool[31]{
            EncType::guard, EncType::drunkGuy, EncType::soldier, EncType::giant, EncType::priest,
            EncType::elf, EncType::dwarf, EncType::theRock, EncType::trader, EncType::bard,
            EncType::loli, EncType::shota, EncType::zombie, EncType::skeleton, EncType::witch,
            EncType::ghost, EncType::yourself, EncType::blurp, EncType::smallRat, EncType::rat,
            EncType::giantRat, EncType::colossalSpider, EncType::ratman, EncType::goblin,
            EncType::hobgoblin, EncType::orc, EncType::kobold, EncType::kockbold,
            EncType::cockblin, EncType::bugBox, EncType::crackman,
    };
    return encounterPool[Random::get(0, 30)];
}

Creatures::Encounter::EncounterType Locale::generateStrongholdEncounter()
{
    constexpr EncType encounterPool[12]{
            EncType::guard, EncType::soldier, EncType::torturer, EncType::elf, EncType::dwarf,
            EncType::prisoner, EncType::theRock, EncType::witch, EncType::theBeer,
            EncType::stoneGolem, EncType::smallRat, EncType::rat,
    };
    return encounterPool[Random::get(0, 11)];
}

Creatures::Encounter::EncounterType Locale::generateAnyEncounter()
{
    return static_cast<EncType>(Random::get(0, static_cast<int>(EncType::none)));
}

void Locale::reset()
{
    
}

void Locale::goToNextRoom()
{
    if ((m_rooms.size() - 1) > m_currentRoom)
        ++m_currentRoom;
}

void Locale::goToPreviousRoom()
{
    if (m_currentRoom > 0)
        --m_currentRoom;
}

Creatures::Encounter::EncounterType Locale::getCurrentRoomEncounterType() const
{
    return m_rooms[m_currentRoom].m_encounterOfTheRoom;
}