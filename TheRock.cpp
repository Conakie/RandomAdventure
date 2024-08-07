
#include "TheRock.h"

void Creatures::Encounter::TheRock::talk()
{
}

void Creatures::Encounter::TheRock::setName()
{
    name = "The Rock";
}

void Creatures::Encounter::TheRock::setStats()
{
    maxHp = 5 + (3.5 * (lvl - 1));
    maxAtk = 1.5 + (2.5 * lvl);
    maxDef = 20;
    critRate = 0;
    critDmg = 0;
    xp = 5;

    hp = maxHp;
    atk = maxAtk;
    def = maxDef;
}
