#include "TheBeer.h"

void Creatures::Encounter::TheBeer::talk()
{
}

void Creatures::Encounter::TheBeer::setName()
{
    name = "The Beer";
}

void Creatures::Encounter::TheBeer::setStats()
{
    maxHp = 0.69 + (0.69 * (lvl - 1));
    maxAtk = 1 + (0.1 * lvl);
    maxDef = -100;
    critRate = 0;
    critDmg = 0;
    xp = 5;

    hp = maxHp;
    atk = maxAtk;
    def = maxDef;
}
