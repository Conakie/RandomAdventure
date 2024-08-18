
#include <iostream>
#include "The104.h"
#include "Input.h"
#include "Everywhere Used Func.h"
#include "Random.h"



void Creatures::Encounter::The104::talk()
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

void Creatures::Encounter::The104::setName()
{
    name = "The 104";
}

void Creatures::Encounter::The104::setStats()
{
    maxHp = 26 + (26 * (lvl - 1));
    maxAtk = 0 + (0.7 * lvl);
    maxDef = 0;
    critRate = 0;
    critDmg = 0;
    xp = 1;

    hp = maxHp;
    atk = maxAtk;
    def = maxDef;
}

void Creatures::Encounter::The104::dialogue()
{
	std::cout << "{F[f(_a)A!(_o)O!(_t)$(_n)1=,(_isle)(_n)*(_a)(le).?=/(_isle)^\\(_n)*(_a)"
		<< "s.?(_t)f.?(_n)*(_a)s.?(_t)f.?(_a)a.?]}{M[m(_a)A!(_f)F!(_o)O!(_n)=(_nlm)"
		<< "=/(_nlm)(_n)*(_f)f.?(_o)(on).?\" \"(_o)o.?(_n)(_n)*(_a)a.?=(_nlm)(_n)*"
		<< "(_a)(le).?=\\]}";
	if (Random::get(0, 99) < 49)
		m_isUnderAttack = true;
	else
		m_isGone = true;

	m_canTalk = false;
	waitForAnyKey();
}
