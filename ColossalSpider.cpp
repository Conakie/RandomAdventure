
#include <iostream>
#include "ColossalSpider.h"
#include "Talk To Encounters English.h"



void Creatures::Encounter::ColossalSpider::talk()
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

void Creatures::Encounter::ColossalSpider::setName()
{
    name = "Colossal Spidey";
}

void Creatures::Encounter::ColossalSpider::setStats()
{
    maxHp = 8 + (4.5 * (lvl - 1));
    maxAtk = 2 + (1.05 * lvl);
    maxDef = 0;
    critRate = 0;
    critDmg = 0;
    xp = 3;

    hp = maxHp;
    atk = maxAtk;
    def = maxDef;
}
