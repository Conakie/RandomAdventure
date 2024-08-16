
#include <iostream>
#include "ColossalRat.h"
#include "Talk To Encounters English.h"



void Creatures::Encounter::ColossalRat::talk()
{
    if (m_canTalk && !(m_isUnderAttack))
    {
        rats(this);
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

void Creatures::Encounter::ColossalRat::setName()
{
    name = "Colossal Rat";
}

void Creatures::Encounter::ColossalRat::setStats()
{
    maxHp = 8 + (4.5 * (lvl - 1));
    maxAtk = 3 + (1.5 * lvl);
    maxDef = 0;
    critRate = 0;
    critDmg = 0;
    xp = 3;

    hp = maxHp;
    atk = maxAtk;
    def = maxDef;
}
