
#include <iostream>
#include "SmallRat.h"
#include "Talk To Encounters English.h"



void Creatures::Encounter::SmallRat::talk()
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

void Creatures::Encounter::SmallRat::setName()
{
    name = "Small Rat";
}

void Creatures::Encounter::SmallRat::setStats()
{
    maxHp = 2 + (1 * (lvl - 1));
    maxAtk = 0.2 + (0.1 * lvl);
    maxDef = 0;
    critRate = 0;
    critDmg = 0;
    xp = 1;

    hp = maxHp;
    atk = maxAtk;
    def = maxDef;
}
