
#include "EnormousRat.h"

void Creatures::Encounter::EnormousRat::talk()
{
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
