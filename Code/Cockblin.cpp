
#include <iostream>
#include "Cockblin.h"
#include "Input.h"
#include "Everywhere Used Func.h"



void Creatures::Encounter::Cockblin::talk()
{
	if (m_canTalk && !(m_isUnderAttack))
	{
		dialogue();
	}
	else
	{
		if (m_isUnderAttack)
		{
			std::cout << "Kelmod: \"" << name << " refuses to talk after you attacked it.\"\n";
		}
		else
		{
			std::cout << "Kelmod: \"You have already talked to him.\n";
		}
	}
}

void Creatures::Encounter::Cockblin::setName()
{
    name = "Cockblin";
}

void Creatures::Encounter::Cockblin::setStats()
{
    maxHp = 5.65 + (4 * (lvl - 1));
    maxAtk = 0.5 + (1 * lvl);
    maxDef = -69;
    critRate = 0;
    critDmg = 0;
    xp = 1;

    hp = maxHp;
    atk = maxAtk;
    def = maxDef;
}

void Creatures::Encounter::Cockblin::dialogue()
{
	std::cout << "A nice dialogue here.\n"
		<< "And another one here. This is funny instead.\n"
		<< "The player said something that made the Cockblin angry.\n";
	waitForAnyKey();
	std::cout << "Now the Cockblin wants to figth the player.\n"
		<< "Good luck. I should really put more stuff here.\n";
	m_isUnderAttack = true;
	m_canTalk = false;
	waitForAnyKey();
}
