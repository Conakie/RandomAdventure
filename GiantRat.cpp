
#include "GiantRat.h"

void Creatures::Encounter::GiantRat::talk()
{
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
