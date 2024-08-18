
#include <iostream>
#include "StoneGolem.h"
#include "Random.h"
#include "Everywhere Used Func.h"



void Creatures::Encounter::StoneGolem::talk()
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

void Creatures::Encounter::StoneGolem::dialogue()
{
    if (Random::get(0, 99) > 69)
    {
        std::cout << "Stone Golem: \"Crick crack\nYour neck is goin' crock!\"\n";
        m_isUnderAttack = true;
    }
    else
    {
        std::cout << "Stone Golem: \"Crick crock\nI'm sniffin' crack!\n";
        m_isGone = true;
    }

    m_canTalk = false;
    waitForAnyKey();
}
