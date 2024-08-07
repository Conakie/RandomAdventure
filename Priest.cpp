
#include <iostream>
#include "Priest.h"



void Creatures::Encounter::Priest::talk()
{
}

void Creatures::Encounter::Priest::thinkAndAct()
{
    if (m_player)
    {
        if (isAlive() && !isUnderAttack && canTalk)
        {
            talk();
        }
        else
        {
            std::cout << "Kelmod: \"Do something man. I'm bored.\"\n";
        }
    }
    else
    {
        std::cout << "The priest ignores you and keeps going his way.\n";
        isGone = true;
    }
}

void Creatures::Encounter::Priest::setName()
{
    name = "Priest";
}

void Creatures::Encounter::Priest::setStats()
{
    maxHp = 11 + (11 * (lvl - 1));
    maxAtk = 1 + (1 * lvl);
    maxDef = 1;
    critRate = 0;
    critDmg = 0;
    xp = 1;

    hp = maxHp;
    atk = maxAtk;
    def = maxDef;
}
