
#include <iostream>
#include "DrunkGuy.h"
#include "Playerz.h"

void Creatures::Encounter::DrunkGuy::attack(Creatures::Player::Playerz& player)
{
    std::cout << name << " throws a wine bottle at you doing " << atk << " dmg.\n";
    m_player->takeDamage(atk);
}

void Creatures::Encounter::DrunkGuy::talk()
{
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