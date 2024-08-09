
#include "SmallRat.h"

void Creatures::Encounter::SmallRat::talk()
{
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
