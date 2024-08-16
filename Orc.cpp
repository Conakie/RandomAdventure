
#include <iostream>
#include "Orc.h"
#include "Input.h"
#include "Everywhere Used Func.h"
#include "Random.h"



void Creatures::Encounter::Orc::talk()
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

void Creatures::Encounter::Orc::setName()
{
    name = "Orc";
}

void Creatures::Encounter::Orc::setStats()
{
    maxHp = 9 + (7 * (lvl - 1));
    maxAtk = 2.25 + (2.25 * lvl);
    maxDef = 5;
    critRate = 0;
    critDmg = 0;
    xp = 3;

    hp = maxHp;
    atk = maxAtk;
    def = maxDef;
}

void Creatures::Encounter::Orc::dialogue()
{
	std::cout << "HAI\n"
		<< "CAN HAS STDIO ?\n"
		<< "I HAS A VAR\n"
		<< "IM IN YR LOOP\n"
		<< "\tUP VAR!!1\n"
		<< "\tVISIBLE VAR\n"
		<< "\tIZ VAR BIGGER THAN 10 ? KTHX\n"
		<< "IM OUTTA YR LOOP\n"
		<< "KTHXBYE\n";
	if (Random::get(0, 99) < 49)
		m_isUnderAttack = true;
	else
		m_isGone = true;

	m_canTalk = false;
	waitForAnyKey();
}
