
#include <iostream>
#include "TheRock.h"
#include "Everywhere Used Func.h"



void Creatures::Encounter::TheRock::talk()
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

void Creatures::Encounter::TheRock::setName()
{
    name = "The Rock";
}

void Creatures::Encounter::TheRock::setStats()
{
    maxHp = 5 + (3.5 * (lvl - 1));
    maxAtk = 1.5 + (2.5 * lvl);
    maxDef = 20;
    critRate = 0;
    critDmg = 0;
    xp = 5;

    hp = maxHp;
    atk = maxAtk;
    def = maxDef;
}

void Creatures::Encounter::TheRock::dialogue()
{
    std::cout << "Nanre: \"Why do you want to talk to a rock?\n"
        << "It's not even the person with the same name.\n"
        << "Oh, maybe you imagined it was him. Sorry, my bad. It's not him.\"\n";
    waitForAnyKey();
    std::cout << "One day, one day you'll be able to find that person.\n"
        << "That day will be when I'll go to hell, so pretty soon.\n"
        << "Be careful, that rock is angry! See ya.\"\n";

    m_isUnderAttack = true;
    waitForAnyKey();
}
