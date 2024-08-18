
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
    if (m_canTalk && !(m_isUnderAttack))
    {
        dialogue();
    }
    else
    {
        if (m_isUnderAttack)
        {
            std::cout << "Kelmod: \"" << name << " refuses to talk after you attacked it.\"\n";
        }
        else
        {
            std::cout << "Kelmod: \"You have already talked to him.\n";
        }
    }
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

void Creatures::Encounter::Giant::dialogue()
{
    std::cout << name << ": \">++++++++[<+++++++++>-]<.\n"
        << "> ++++[<++++++ + >-]<+.\n"
        << "++++++ + ..\n"
        << "++ + .\n"
        << ">> ++++++[<++++++ + >-]<++.\n"
        << "------------.\n"
        << ">++++++[<++++++++ + >-]<+.\n"
        << "<.\n"
        << "++ + .\n"
        << "------.\n"
        << "--------.\n"
        << ">> > ++++[<++++++++>-] < +.\"\n";

    m_isGone = true;
    m_canTalk = false;
    waitForAnyKey();
}
