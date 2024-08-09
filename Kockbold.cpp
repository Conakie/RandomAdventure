
#include "Kockbold.h"

void Creatures::Encounter::Kockbold::talk()
{
}

void Creatures::Encounter::Kockbold::setName()
{
    name = "Kockbold";
}

void Creatures::Encounter::Kockbold::setStats()
{
    maxHp = 5.65 + (5.65 * (lvl - 1));
    maxAtk = 0.55 + (1 * lvl);
    maxDef = -69;
    critRate = 0;
    critDmg = 0;
    xp = 1;

    hp = maxHp;
    atk = maxAtk;
    def = maxDef;
}
