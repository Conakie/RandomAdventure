
#include <iostream>
#include "Talk To Encounters English.h"
#include "Everywhere Used Func.h"
#include "Encounter Stats.h"
#include "Input.h"
#include "Stats.h"
#include "Trader.h"



void trader()
{

    std::cout << "Trader: \"Hello, hello!\n"
        << "If you wanted something I'm sorry to announce I don't have anything to sell at the "
        << "moment.\"\n";

    waitForAnyKey();

    std::cout << "Trader: \"I'm resupplying my stock right now.\n"
        << "Be sure to come back later~\"\n"
        << "(The trader goes away)\n";

    encounter().setIsGone(true);
    encounter().setCanTalk(false);

}

void Creatures::Encounter::Trader::talk()
{
}

void Creatures::Encounter::Trader::thinkAndAct()
{
    if (m_player)
    {
        if (isAlive() && !isUnderAttack && canTalk)
        {
            talk();
        }
        else if (isUnderAttack)
        {
            isGone = true;
        }
        else
        {
            std::cout << "Kelmod: \"Do something man. I'm bored.\"\n";
        }
    }
    else
    {
        std::cout << "The priest ignores you and keeps going his way.\n";
        isGone = true;
    }
}

void Creatures::Encounter::Trader::setName()
{
    name = "Trader";
}

void Creatures::Encounter::Trader::setStats()
{
    maxHp = 10 + (10 * (lvl - 1));
    maxAtk = 0 + (0.5 * lvl);
    maxDef = -60;
    critRate = 0;
    critDmg = 0;
    xp = 1;

    hp = maxHp;
    atk = maxAtk;
    def = maxDef;
}
