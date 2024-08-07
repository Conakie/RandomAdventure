
#include <iostream>
#include "Talk To Encounters English.h"
#include "Everywhere Used Func.h"
#include "Encounter Stats.h"
#include "Input.h"
#include "Stats.h"
#include "Random.h"
#include "Print Errors.h"
#include "Ghost.h"



void ghost()
{

	switch (Random::get(0, 6))
	{
	case 0:
		std::cout << "Ghost: \"Boo!\"\n";
		break;
	case 1:
		std::cout << "Ghost: \"I see you~\"\n";
		break;
	case 2:
		std::cout << "Ghost: \"I can hear you~\"\n";
		break;
	case 3:
		std::cout << "Ghost: \"Where are you~?\"\n";
		break;
	case 4:
		std::cout << "Ghost: \"What are you doing, step-bro~\"\n";
		break;
	case 5:
		std::cout << "Ghost: \"Help me, I'm stuck onii-chan~\"\n";
		break;
	case 6:
		std::cout << "Ghost: \"8===>\"\n";
		break;

	default:
		PrintError::wrongRandomNumber();
		break;
	}

}

void Creatures::Encounter::Ghost::talk()
{
}

void Creatures::Encounter::Ghost::thinkAndAct()
{
	if (isUnderAttack && isAlive() && !isGone)
	{
		if (m_player)
		{
			heal(2);
			attack(*m_player);
		}
		else
			heal(4);
	}
	else if (isGone)
	{
		dropItems();
	}
	else
	{
		std::cout << "Kelmod: \"" << name << " is waiting...\"\n";
	}
}

void Creatures::Encounter::Ghost::setName()
{
	name = "Ghost";
}

void Creatures::Encounter::Ghost::setStats()
{
	maxHp = 7 + (7 * (lvl - 1));
	maxAtk = 1 + (1 * lvl);
	maxDef = 10;
	critRate = 0;
	critDmg = 0;
	xp = 1;

	hp = maxHp;
	atk = maxAtk;
	def = maxDef;
}
