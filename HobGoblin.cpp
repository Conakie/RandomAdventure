
#include "HobGoblin.h"

void Creatures::Encounter::HobGoblin::talk()
{
}

void Creatures::Encounter::HobGoblin::setName()
{
    name = "Hob Goblin";
}

void Creatures::Encounter::HobGoblin::setStats()
{
    maxHp = 8.5 + (6.5 * (lvl - 1));
    maxAtk = 1.5 + (1.5 * lvl);
    maxDef = 5;
    critRate = 0;
    critDmg = 0;
    xp = 1;

    hp = maxHp;
    atk = maxAtk;
    def = maxDef;
}
