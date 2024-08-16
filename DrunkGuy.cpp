
#include <iostream>
#include "DrunkGuy.h"
#include "Playerz.h"
#include "Everywhere Used Func.h"
#include "Input.h"
#include "Random.h"

void Creatures::Encounter::DrunkGuy::attack(Creatures::Player::Playerz& player)
{
    std::cout << name << " throws a wine bottle at you doing " << atk << " dmg.\n";
    m_player->takeDamage(atk);
}

void Creatures::Encounter::DrunkGuy::talk()
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
            std::cout << "Kelmod: \"You have already talked.\n";
        }
    }
}

void Creatures::Encounter::DrunkGuy::setName()
{
    name = "Drunky";
}

void Creatures::Encounter::DrunkGuy::setStats()
{
	maxHp = 8 + (5 * (lvl - 1));
	maxAtk = 1 + (1 * lvl);
	maxDef = 0;
	critRate = 0;
	critDmg = 0;
	xp = 1;

	hp = maxHp;
	atk = maxAtk;
	def = maxDef;
}

void Creatures::Encounter::DrunkGuy::dialogue()
{
    std::cout << '(' << name << " is saying stuff you cannot understand)\n"
        << "(After you tried to understand what he's saying for 5 times, you go away)\n";
    if (Random::get(0, 99) < 24)
    {
        std::cout << "(He shouts something. He looks angry)\n"
            << "(It seems he wants to kill you because you ignored him)\n";
        m_isUnderAttack = true;
    }
    else
    {
        std::cout << "(He falls on the ground. Sleeping)\n"
            << "(Since he's fine you go away)\n";
        m_isGone = true;
    }

    waitForAnyKey();
    m_canTalk = false;
}
