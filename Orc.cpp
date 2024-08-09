
#include "Orc.h"

void Creatures::Encounter::Orc::talk()
{
}

void Creatures::Encounter::Orc::setName()
{
    name = "Orc";
}

void Creatures::Encounter::Orc::setStats()
{
    maxHp = 9 + (7 * (lvl - 1));
    maxAtk = 2.25 + (2.25 * lvl);
    maxDef = 5;
    critRate = 0;
    critDmg = 0;
    xp = 3;

    hp = maxHp;
    atk = maxAtk;
    def = maxDef;
}
