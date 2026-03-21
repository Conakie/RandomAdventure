
#include <iostream>
#include "Places.h"
#include "Random.h"
#include "Locale.h"



PlacesID Places::generatePlace()
{
	return m_location;
}

void Places::printPlace() const
{
	switch (m_location)
	{
	case PlacesID::dungeon:
        printDungeon();
		break;
	case PlacesID::village:
        printVillage();
		break;
	case PlacesID::cave:
        printCave();
		break;
	case PlacesID::forest:
        printForest();
		break;
	case PlacesID::stronghold:
        printStronghold();
		break;
	case PlacesID::unknown:
        printUnknown();
		break;
	default:
        printUnknown();
		break;
	}
}

void Places::generateLocation()
{
	switch (m_location)
	{
	case PlacesID::dungeon:
		m_location = static_cast<PlacesID>(Random::get(0, 3));
		if (m_location == PlacesID::village)
			m_location = PlacesID::cave;
		break;
	case PlacesID::village:
        m_location = static_cast<PlacesID>(Random::get(0, 3));
		if (m_location == PlacesID::dungeon)
			m_location = PlacesID::cave;
		break;
	case PlacesID::cave:
		m_location = static_cast<PlacesID>(Random::get(0, 3));
		break;
	case PlacesID::forest:
		m_location = static_cast<PlacesID>(Random::get(0, 3));
		break;
	case PlacesID::unknown:
		m_location = static_cast<PlacesID>(Random::get(0, 3));
		break;
	default:
		m_location = static_cast<PlacesID>(Random::get(0, 3));
		break;
	}
}

void Places::generateRoom()
{
	switch (m_location)
	{
	case PlacesID::dungeon:
        m_roomID = Random::get(1, 10);
		break;
	case PlacesID::village:
		m_roomID = Random::get(1, 10);
		break;
	case PlacesID::cave:
		m_roomID = Random::get(1, 10);
		break;
	case PlacesID::forest:
		m_roomID = Random::get(1, 10);
		break;
	case PlacesID::stronghold:
		m_roomID = Random::get(1, 10);
		break;
	case PlacesID::unknown:
		m_roomID = Random::get(1, 10);
		break;
	default:
		m_roomID = Random::get(1, 10);
		break;
	}
}

void Places::printDungeon() const
{
	std::cout << std::endl;
	if (m_justEntered)
		std::cout << "The dungeon you just entered is a dungeon\n";
	switch (m_roomID)
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
	default:
        std::cout << "You enter a room. There is no distinctive feature in this room.\n";
		break;
	}
}

void Places::printVillage() const
{
	if (m_justEntered)
		std::cout << "You enter a village with many small houses and a few stores all around.\n";

	switch (m_roomID)
	{
	case 0:
		std::cout << "You wander around one of the main streets. Stores are everywhere you look.\n"
			<< " ";
	default:
		break;
	}
}

void Places::printCave() const
{
}

void Places::printForest() const
{
}

void Places::printStronghold() const
{
}

void Places::printUnknown() const
{
}
