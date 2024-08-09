
#include "Cockblin.h"

void Creatures::Encounter::Cockblin::talk()
{
}

void Creatures::Encounter::Cockblin::setName()
{
    name = "Cockblin";
}

void Creatures::Encounter::Cockblin::setStats()
{
    maxHp = 5.65 + (4 * (lvl - 1));
    maxAtk = 0.5 + (1 * lvl);
    maxDef = -69;
    critRate = 0;
    critDmg = 0;
    xp = 1;

    hp = maxHp;
    atk = maxAtk;
    def = maxDef;
}
