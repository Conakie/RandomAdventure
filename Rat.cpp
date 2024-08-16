
#include <iostream>
#include "Rat.h"
#include "Talk To Encounters English.h"



void Creatures::Encounter::Rat::talk()
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

void Creatures::Encounter::Rat::setName()
{
    name = "Rat";
}

void Creatures::Encounter::Rat::setStats()
{
    maxHp = 3 + (1.5 * (lvl - 1));
    maxAtk = 0.5 + (0.4 * lvl);
    maxDef = 0;
    critRate = 0;
    critDmg = 0;
    xp = 1;

    hp = maxHp;
    atk = maxAtk;
    def = maxDef;
}
