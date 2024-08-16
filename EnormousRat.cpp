
#include <iostream>
#include "EnormousRat.h"
#include "Talk To Encounters English.h"



void Creatures::Encounter::EnormousRat::talk()
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

void Creatures::Encounter::EnormousRat::setName()
{
    name = "Enormous Rat";
}

void Creatures::Encounter::EnormousRat::setStats()
{
    maxHp = 7 + (3.5 * (lvl - 1));
    maxAtk = 2 + (1.9 * lvl);
    maxDef = 0;
    critRate = 0;
    critDmg = 0;
    xp = 2;

    hp = maxHp;
    atk = maxAtk;
    def = maxDef;
}
