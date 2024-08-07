#include "Witch.h"

void Creatures::Encounter::Witch::talk()
{
}

void Creatures::Encounter::Witch::setName()
{
    name = "Witch";
}

void Creatures::Encounter::Witch::setStats()
{
    maxHp = 8.8 + (6.6 * (lvl - 1));
    maxAtk = 1 + (3 * lvl);
    maxDef = -1;
    critRate = 0;
    critDmg = 0;
    xp = 1;

    hp = maxHp;
    atk = maxAtk;
    def = maxDef;
}
