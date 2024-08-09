
#include "Rat.h"

void Creatures::Encounter::Rat::talk()
{
}

void Creatures::Encounter::Rat::setName()
{
    name = "Rat";
}

void Creatures::Encounter::Rat::setStats()
{
    maxHp = 3 + (1.5 * (lvl - 1));
    maxAtk = 0.5 + (0.4 * lvl);
    maxDef = 0;
    critRate = 0;
    critDmg = 0;
    xp = 1;

    hp = maxHp;
    atk = maxAtk;
    def = maxDef;
}
