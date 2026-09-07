
#include <iostream>
#include <utility>
#include "Locale.h"
#include "Random.h"
#include "EncounterType.h"
#include "Loot.h"
#include "PlacesID.h"
#include "PrintErrors.h"
#include "Items.h"
#include <print>

void Localez::generateLocale()
{
    // randomly selects a locale type and variant
    m_localeType = static_cast<PlacesID>(Random::get(0, 4));
    //m_localeType = PlacesID::dungeon;

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

Creatures::Encounter::EncounterType Localez::generateEncounter()
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

void Localez::generateTreasureRoom()
{
    // sets the last room to be a treasure room. Always.
    size_t index = m_rooms.size() - 1;

    m_rooms[index].m_roomID = 0;
    m_rooms[index].m_encounterOfTheRoom = generateEncounter();
    m_rooms[index].m_lootAmount = LootAmount::treasure;
    m_rooms[index].m_lightLevel = static_cast<LightAmount>(Random::get(1, 3));
}

Creatures::Encounter::EncounterType Localez::generateDungeonEncounter()
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

Creatures::Encounter::EncounterType Localez::generateVillageEncounter()
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

Creatures::Encounter::EncounterType Localez::generateCaveEncounter()
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

Creatures::Encounter::EncounterType Localez::generateForestEncounter()
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

Creatures::Encounter::EncounterType Localez::generateStrongholdEncounter()
{
    constexpr EncType encounterPool[12]{
            EncType::guard, EncType::soldier, EncType::torturer, EncType::elf, EncType::dwarf,
            EncType::prisoner, EncType::theRock, EncType::witch, EncType::theBeer,
            EncType::stoneGolem, EncType::smallRat, EncType::rat,
    };
    return encounterPool[Random::get(0, 11)];
}

Creatures::Encounter::EncounterType Localez::generateAnyEncounter()
{
    return static_cast<EncType>(Random::get(0, static_cast<int>(EncType::none)));
}

void Localez::printDungeonRoom() const
{
    if (m_rooms[m_currentRoom].m_hasBeenEntered)
    {
        std::print("You go back to a room you have already entered before.\n");
    }
    else
    {
        switch (m_rooms[m_currentRoom].m_roomID)
        {
        case 0:
            std::cout << "You move to a long rectangular room, with half columns following each side.\n";
            break;
        case 1:
            std::cout << "After opening the door, you find yourself in a small room with a single\n"
                << "torch on the wall.\nOn the ceiling there is a gigantic painting representing\n"
                << "a man with a pike in his left hand and a crown on the right hand.\n";
            break;
        case 2:
            std::cout << "The door broke down at your touch. The wood was rotten.\n"
                << "On the left wall there is an altar with lit candles on it.\n";
            break;
        case 3:
            std::cout << "The doors creaks as you open it. The room is a large circular room\n"
                << "with a large chandelier hanging from the ceiling.\n"
                << "There are paintings on the walls representing soldiers.\n";
            break;
        case 4:
            std::cout << "A large stone table is in the center of this room.\n"
                << "Chairs surround it. Everything is covered with dust and debris from the ceiling.\n"
                << "A wall fell down, showing the rock from which the dungeon was carved.\n";
            break;
        case 5:
            std::cout << "There is no door, just a long corridor badly lit by torches.\n"
                << "The walls are made of stone and there is dust everywhere.\n";
            break;
        case 6:
            std::cout << "As you enter, you find the room being fairly small and empty.\n"
                << "There are no decorations, no furniture, nothing.\n"
                << "It's just a room with four walls and a ceiling.\n";
            break;
        case 7:
            std::cout << "You almost fell in a deep hole when entering, but you avoid it in time.\n"
                << "The room is cold and the walls are falling apart like almost anything you can see.\n"
                << "The floor is made of stone, but it is cracked and uneven.\n";
            break;
        case 8:
            std::cout << "The door closes behind you, but when it closed it broke.\n"
                << "The door is now on the ground broken in half.\n"
                << "You hope nobody will mind as you continue to explore the room.\n";
            break;
        case 9:
            std::cout << "This room is pretty humid, the walls have water dripping from holes.\n"
                << "The floor is made of stone tiles, but they are covered in moss and water.\n";
            break;
        case 10:
            std::cout << "As you enter, you see murals representing a certain deity.\n"
                << "They are pretty old and faded, but you can still make out the details.\n"
                << "Aside from those, there is nothing else of interest.\n";
            break;
        default:
            std::cout << "You enter a room. There is no distinctive feature in this room.\n";
            break;
        }
    }
}

void Localez::printVillageRoom() const
{
    if (m_rooms[m_currentRoom].m_hasBeenEntered)
    {
        std::print("You go back to a street you have already visited.\n");
    }
    else
    {
        switch (m_rooms[m_currentRoom].m_roomID)
        {
        case 0:
            std::cout << "You are walking on a main road with cobbled stones.\n"
                << "Tall houses surround you, stores of all kinds on the ground floors.\n"
                << "Many people are walking around, some cats mixed with the crowd.\n";
            break;
        case 1:
            std::cout << "This street is a calm one. Not many people are here.\n"
                << "There isn't anything interesting of note, but it is a calm and nice place.\n"
                << "Living here wouldn't be so bad if you weren't wandering around the world.\n";
            break;
        case 2:
            std::cout << "You enter a narrow street, but many use this to go around.\n"
                << "All the houses are made of wood and stone, with no balconies.\n";
            break;
        case 3:
            std::cout << "You reach a big square with a large fountain at the center.\n"
                << "Many stalls can be found all around the square.\n"
                << "The place is really crowded, but you can still walk around easily.\n";
            break;
        case 4:
            std::cout << "You are now in an old square. It looks a little rundown.\n"
                << "The houses here have less floors compared to other parts of the village.\n"
                << "This place is also pretty much empty, there is almost nobody here.\n";
            break;
        case 5:
            std::cout << "This place is full of restaurants and taverns as well as stores.\n"
                << "The smell of food is everywhere. You would eat a human for how nice it is.\n"
                << "But you won't because it is definitely not a good idea. For now.\n";
            break;
        default:
            std::cout << "You are walking on a random street. Nothing interesting about it.\n";
            break;
        }
    }
}

void Localez::printCaveRoom() const
{
    if (m_rooms[m_currentRoom].m_hasBeenEntered)
    {
        std::print("You go back to a cave tunnel you have been in earlier.\n");
    }
    else
    {
        switch (m_rooms[m_currentRoom].m_roomID)
        {
        case 0:
            std::cout << "";
            break;
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        default:
            std::print("You enter a cave tunnel. Nothing interesting to see.\n");
            break;
        }
    }
}

void Localez::printForestRoom() const
{
    if (m_rooms[m_currentRoom].m_hasBeenEntered)
    {
        std::print("");
    }
    else
    {
        switch (m_rooms[m_currentRoom].m_roomID)
        {
        default:
            std::print("");
            break;
        }
    }
}

void Localez::printStrongholdRoom() const
{
    if (m_rooms[m_currentRoom].m_hasBeenEntered)
    {
        std::print("");
    }
    else
    {
        switch (m_rooms[m_currentRoom].m_roomID)
        {
        default:
            std::print("");
            break;
        }
    }
}

void Localez::reset()
{
    
}

bool Localez::goToNextRoom()
{
    if ((m_rooms.size() - 1) > m_currentRoom)
    {
        ++m_currentRoom;
        m_rooms[m_currentRoom].m_hasBeenEntered = true;
        printCurrentRoom();
        return false;
    }
    return true;
}

bool Localez::goToPreviousRoom()
{
    if (m_currentRoom > 0)
    {
        --m_currentRoom;
        return false;
    }
    return true;
}

void Localez::printCurrentRoom() const
{
    switch (m_localeType)
    {
    case PlacesID::dungeon:
        printDungeonRoom();
        break;
    case PlacesID::village:
        printDungeonRoom();
        break;
    case PlacesID::cave:
        printDungeonRoom();
        break;
    case PlacesID::forest:
        printDungeonRoom();
        break;
    case PlacesID::stronghold:
        printDungeonRoom();
        break;
    case PlacesID::unknown:
        Print::Errors::somethingWentWrong("PlacesID::unknown", "Localez::PrintCurrentRoom()");
        break;
    default:
        Print::Errors::somethingWentWrong("Default branch", "Localez::PrintCurrentRoom()");
        break;
    }
}

void Localez::removeCurrentRoomEncounter()
{
    m_rooms[m_currentRoom].m_encounterOfTheRoom = Creatures::Encounter::EncounterType::none;
}

std::pair<Items::ItemName, int> Localez::getLootFromCurrentRoom()
{
    std::pair<Item, int> loot{ Item::none, 0 };
    
    switch (m_rooms[m_currentRoom].m_lootAmount)
    {
    case LootAmount::none:
        return loot;
    case LootAmount::low:
        loot.first = Item::smallHealingPotion;
        loot.second = Random::get(1, 3);
        return loot;
    case LootAmount::medium:
        loot.first = Item::mediumHealingPotion;
        loot.second = Random::get(1, 3);
        return loot;
    case LootAmount::high:
        loot.first = Item::molotov;
        loot.second = Random::get(1, 3);
        return loot;
    case LootAmount::treasure:
        loot.first = Item::magicScroll;
        loot.second = Random::get(1, 3);
        return loot;
    case LootAmount::unknown:
        loot.first = Item::herbs;
        loot.second = Random::get(1, 3);
        return loot;
    default:
        return loot;
    }
}

void Localez::deleteLocale()
{
    m_rooms.clear();
    m_currentRoom = 0;
}

Creatures::Encounter::EncounterType Localez::getCurrentRoomEncounterType() const
{
    return m_rooms[m_currentRoom].m_encounterOfTheRoom;
}