
#include <iostream>
#include "Player Stats.h"
#include "Prng.h"
#include "Encounters.h"
#include "Playerz.h"



void Playerz::heal(double healing)
{

	std::cout << m_player.name <<" healed of " << healing << "hp.\n";
	if (m_player.hp + healing >= m_player.maxHp)
	{

		m_player.hp = m_player.maxHp;

	}
	else
	{

		m_player.hp += healing;

	}
	std::cout << "Now you have " << m_player.hp << "hp.\n";

}



void Playerz::takeDamage(double damage)
{
	// add damageType to say what is the cause for the damage
	m_player.hp -= damage;
	std::cout << "\n" << m_player.name << " took " << damage << "hp of damage.\n";

	if (m_player.hp <= 0)
	{

		std::cout << "You died. Haha, loser!\n";

	}
	else
	{

		std::cout << "Now you have " << m_player.hp << "hp.\n";

	}

}



void Playerz::increaseXpAndCheckForLvlUp(short value)
{

	m_player.xp += value;
	std::cout << "Xp increased of " << value;
	lvlUp();

}



void Playerz::printStats() const
{

	std::cout << "\n\nYour stats are:\n"
		<< "Health: " << m_player.hp << "\n"
		<< "Max Health: " << m_player.maxHp << "\n"
		<< "Attack: " << m_player.atk << "\n"
		<< "Max Attack: " << m_player.maxAtk << "\n"
		<< "Xp: " << m_player.xp << "\n"
		<< "Xp to reach for level up: " << m_player.lvlUpXp << "\n"
		<< "Level: " << m_player.lvl << "\n"
		<< "Crit Rate: " << m_player.critRate << "\n"
		<< "Crit Damage: " << m_player.critDmg << "\n"
		<< "Stamina: " << m_player.stamina << "\n"
		<< "Weight: " << m_player.weight << "\n"
		<< "Strenght: " << m_stats.strenght << "\n"
		<< "Dexterity: " << m_stats.dexterity << "\n"
		<< "Intelligence: " << m_stats.intelligence << "\n"
		<< "Wisdom: " << m_stats.wisdom << "\n"
		<< "Charisma: " << m_stats.charisma << "\n"
		<< "\n\n";

}



void Playerz::resetAllStats()
{

	// reset player character stats
	m_player.hp = 10;
	m_player.maxHp = 10;
	m_player.atk = 4;
	m_player.maxAtk = 4;
	m_player.xp = 0;
	m_player.lvlUpXp = 22;
	m_player.lvl = 1;
	m_player.critRate = 10;
	m_player.critDmg = 2;
	m_player.stamina = 100;
	m_player.weight = 0;

	// reset stats
	m_stats.strenght = 20;
	m_stats.dexterity = 20;
	m_stats.intelligence = 20;
	m_stats.wisdom = 20;
	m_stats.charisma = 20;

	//reset the inventory
	m_inventory.reset();

}



// under this line there are all the private member functions

void Playerz::lvlUp()
{

	// if the xp needed to lvl up is the same as the xp the player has increase stats
	if (m_player.lvlUpXp <= m_player.xp)
	{

		int hpIncrease{ Random::get(1, 10) };
		++m_player.lvl;
		m_player.lvlUpXp += m_player.lvlUpXp * 25 / 100;
		m_player.xp = 0;
		m_player.maxAtk += 1.5;
		m_player.atk += 1.5;
		m_player.maxHp += hpIncrease;
		m_player.hp += hpIncrease;

		std::cout << "Your stats increased.\n";

	}
	else// nothing happens
	{
		// IIOOOII-IIOOOII-IIOOOII-IIOOOII-IIOOOII-IOI-IIIOOII>
	}

}