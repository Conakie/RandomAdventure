
#include <iostream>
#include "Kockbold.h"
#include "Input.h"
#include "Everywhere Used Func.h"



void Creatures::Encounter::Kockbold::talk()
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

void Creatures::Encounter::Kockbold::setName()
{
    name = "Kockbold";
}

void Creatures::Encounter::Kockbold::setStats()
{
    maxHp = 5.65 + (5.65 * (lvl - 1));
    maxAtk = 0.55 + (1 * lvl);
    maxDef = -69;
    critRate = 0;
    critDmg = 0;
    xp = 1;

    hp = maxHp;
    atk = maxAtk;
    def = maxDef;
}

void Creatures::Encounter::Kockbold::dialogue()
{
	std::cout << "Someday I will add a good dialogue here.\n"
		<< "But I am not doing it now.\n"
		<< "Did you know I'm planning to make another game?\n";
	waitForAnyKey();
	std::cout << "It should be a rival to any JRPG with an open world.\n"
		<< "Also, do you want to change the name of this game?\n"
		<< "Just kidding. Not changing the name anytime soon.\n";
	waitForAnyKey();
	std::cout << "Anyway, now the kockbold is gone.\n";


	m_isGone = true;
	m_canTalk = false;
	waitForAnyKey();
}
