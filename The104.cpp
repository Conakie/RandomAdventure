
#include "The104.h"

void Creatures::Encounter::The104::talk()
{
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
