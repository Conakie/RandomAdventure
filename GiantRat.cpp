
#include <iostream>
#include "GiantRat.h"
#include "Talk To Encounters English.h"



void Creatures::Encounter::GiantRat::talk()
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

void Creatures::Encounter::GiantRat::setName()
{
    name = "Giant Rat";
}

void Creatures::Encounter::GiantRat::setStats()
{
    maxHp = 5.5 + (3 * (lvl - 1));
    maxAtk = 1 + (0.9 * lvl);
    maxDef = 0;
    critRate = 0;
    critDmg = 0;
    xp = 1;

    hp = maxHp;
    atk = maxAtk;
    def = maxDef;
}
