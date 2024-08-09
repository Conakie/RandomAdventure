
#include "ColossalRat.h"

void Creatures::Encounter::ColossalRat::talk()
{
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
