
#include "HobGoblin.h"

void Creatures::Encounter::HobGoblin::talk()
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

void Creatures::Encounter::HobGoblin::setName()
{
    name = "Hob Goblin";
}

void Creatures::Encounter::HobGoblin::setStats()
{
    maxHp = 8.5 + (6.5 * (lvl - 1));
    maxAtk = 1.5 + (1.5 * lvl);
    maxDef = 5;
    critRate = 0;
    critDmg = 0;
    xp = 1;

    hp = maxHp;
    atk = maxAtk;
    def = maxDef;
}

void Creatures::Encounter::HobGoblin::dialogue()
{
}
