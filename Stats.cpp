
#include <string_view>
#include <string>
#include "Input.h"
#include "Stats.h"
#include "Playerz.h"
#include "Shielder.h"
#include "Warrior.h"
#include "Mage.h"
#include "Berserker.h"
#include "Thief.h"
#include "Archer.h"
#include "Cleric.h"
#include "Barbarian.h"
#include "Encounterz.h"



//Creatures::Player::Playerz& player()
//{
//	static Creatures::Player::Barbarian s_player{ };
//
//    return s_player;
//}

Creatures::Player::Playerz& player()
{
	return *g_player;
}

Creatures::Player::Playerz* g_player{ nullptr };
Creatures::Encounter::Encounterz* g_encounter{ nullptr };
/*
std::cout << "Short" << sizeof(short) << "\n"
		<< "Int" << sizeof(int) << "\n"
		<< "Double" << sizeof(double) << "\n"
		<< "Long long" << sizeof(long int) << "\n"
		<< "Long double" << sizeof(long double) << "\n"
		<< "\n";
*/

//Encounters& encounter()
//{
//
//    static Encounters s_encounter{ };
//
//    return s_encounter;
//
//}

Creatures::Encounter::Encounterz& encounter()
{
	return *g_encounter;
}

//Playerz player{ };
//Encounters encounter{ };
