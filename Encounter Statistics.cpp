
#include <iostream>
#include "Random Adventure English.h"
#include "Random Adventure Italiano.h"
#include "Encounter Stats.h"
#include "Player Stats.h"
#include "Print Errors.h"
#include "Random.h"
#include "Stats.h"



void increaseXP()
{
	
	// xp will be added to the player and encounter at the end of the function
	short xp{ 0 };


	switch (encounter().getUid())
	{
	case EncounterUid::guard:// Guard

		xp = 1;

		break;

	case EncounterUid::drunkGuy:// Drunk Guy

		xp = 1;

		break;

	case EncounterUid::soldier:// Soldier

		xp = 4;

		break;

	case EncounterUid::torturer:// Torturer

		xp = 1;

		break;

	case EncounterUid::giant:// Giant

		xp = 3;

		break;

	case EncounterUid::cleric:// Cleric

		xp = 1;

		break;

	case EncounterUid::elf:// Elf

		xp = 2;

		break;

	case EncounterUid::dwarf:// Dwarf

		xp = 2;

		break;

	case EncounterUid::prisoner:// Prisoner

		xp = 1;

		break;

	case EncounterUid::theRock:// The Rock

		xp = 3;

		break;

	case EncounterUid::trader:// Trader

		xp = 1;

		break;

	case EncounterUid::bartender:// Bartender

		xp = 1;

		break;

	case EncounterUid::bard:// Bard

		xp = 1;

		break;

	case EncounterUid::loli:// Loli

		xp = 2;

		break;

	case EncounterUid::shota:// Shota

		xp = 2;

		break;

	case EncounterUid::zombie:// Zombie

		xp = 2;

		break;

	case EncounterUid::skeleton:// Skeleton

		xp = 1;

		break;

	case EncounterUid::witch:// Witch

		xp = 1;

		break;

	case EncounterUid::ghost:// Ghost

		xp = 1;

		break;

	case EncounterUid::theBeer:// The Beer

		xp = 1;

		break;

	case EncounterUid::yourself:// Yourself

		xp = 4;

		break;

	case EncounterUid::stoneGolem:// Stone Golem

		xp = 3;

		break;

	case EncounterUid::blurp:

		xp = 1;

		break;

	case EncounterUid::smallRat:// Small rat

		xp = 1;

		break;

	case EncounterUid::rat://Rat

		xp = 1;

		break;

	case EncounterUid::giantRat:// Giant rat

		xp = 1;

		break;

	case EncounterUid::enormousRat:// Enormous rat

		xp = 2;

		break;

	case EncounterUid::colossalRat:// Colossal rat

		xp = 3;

		break;

	case EncounterUid::colossalSpider:// Colossal spider

		xp = 3;

		break;

	case EncounterUid::ratman:// Ratman

		xp = 1;

		break;

	case EncounterUid::goblin:// Goblin

		xp = 1;

		break;

	case EncounterUid::hobgoblin:// Hobgoblin

		xp = 1;

		break;

	case EncounterUid::orc:// Orc

		xp = 2;

		break;

	case EncounterUid::kobold:// Kobold

		xp = 1;

		break;

	case EncounterUid::kockbold:// Kockbold

		xp = 1;

		break;

	case EncounterUid::cockblin:// Cockblin

		xp = 1;

		break;

	case EncounterUid::the104:// 104

		xp = 3;

		break;

	case EncounterUid::errorGuy:// error guy

		xp = 1;

		break;

	case EncounterUid::elesya://Elesya

		xp = -1;

		break;

	case EncounterUid::kelmod:// Kelmod

		xp = -1;

		break;

	case EncounterUid::lenre:// Lenre

		xp = -1;

		break;

	case EncounterUid::necoto:// Necoto

		xp = -1;

		break;

	case EncounterUid::kyo:// Kyo

		xp = -1;

		break;

	case EncounterUid::expN30A:// Exp. N. 30A

		//xp = 1;

		break;

	case EncounterUid::expN30B:// Exp. N. 30B

		//xp = 1;

		break;

	case EncounterUid::expN30C:// Exp. N. 30C

		//xp = 1;

		break;

	case EncounterUid::sila:// Sila

		//xp = 1;

		break;

	case EncounterUid::armNuc:// Arm Nuc

		//xp = 1;

		break;

	case EncounterUid::miiro:// Miiro

		//xp = 1;

		break;

	case EncounterUid::chishao:// Chishao

		//xp = 1;

		break;

	default://Not found

		PrintError::notFound();

		break;
	}

	
	std::cout << "You got " << xp << "xp!\n";
	player().increaseXpAndCheckForLvlUp(xp);
	encounter().increaseXp(xp);

}
