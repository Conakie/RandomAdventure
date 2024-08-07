
#include <iostream>
#include "Talk To Encounters English.h"
#include "Everywhere Used Func.h"
#include "Encounter Stats.h"
#include "Input.h"
#include "Stats.h"
#include "Giant.h"



void giant()
{

    std::cout << "Giant: \"Ahhh, eoh.\n"
        << "uhh, ah eoh aiah\"\n";

}

void Creatures::Encounter::Giant::talk()
{
}

void Creatures::Encounter::Giant::setName()
{
    name = "Giant";
}

void Creatures::Encounter::Giant::setStats()
{
    maxHp = 16.67 + (12.43 * (lvl - 1));
    maxAtk = 0 + (0 * lvl);
    maxDef = 6;
    critRate = 0;
    critDmg = 0;
    xp = 3;

    hp = maxHp;
    atk = maxAtk;
    def = maxDef;
}
