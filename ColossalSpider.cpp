
#include "ColossalSpider.h"

void Creatures::Encounter::ColossalSpider::talk()
{
}

void Creatures::Encounter::ColossalSpider::setName()
{
    name = "Colossal Spidey";
}

void Creatures::Encounter::ColossalSpider::setStats()
{
    maxHp = 8 + (4.5 * (lvl - 1));
    maxAtk = 2 + (1.05 * lvl);
    maxDef = 0;
    critRate = 0;
    critDmg = 0;
    xp = 3;

    hp = maxHp;
    atk = maxAtk;
    def = maxDef;
}
