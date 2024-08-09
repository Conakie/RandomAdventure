
#include "StoneGolem.h"

void Creatures::Encounter::StoneGolem::talk()
{
}

void Creatures::Encounter::StoneGolem::setName()
{
    name = "Stone Golem";
}

void Creatures::Encounter::StoneGolem::setStats()
{
    maxHp = 25 + (22 * (lvl - 1));
    maxAtk = 0.5 + (0.5 * lvl);
    maxDef = 15;
    critRate = 0;
    critDmg = 0;
    xp = 3;

    hp = maxHp;
    atk = maxAtk;
    def = maxDef;
}
