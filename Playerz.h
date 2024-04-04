
#ifndef KIIYUO_PLAYERZ_CLASS_H
#define KIIYUO_PLAYERZ_CLASS_H
#define KCA1


#include <iostream>
#include <string_view>
#include "Player Stats.h"
#include "Object UID.h"
#include "Items.h"
#include "Inventory.h"


#ifndef KNA1

class Encounters;

#endif // !KNA1


class Playerz
{
public:
	Playerz() = default;

	// increase the hp of healing or to max hp
	void heal(double healing);

	// decrease the player hp
	void takeDamage(double damage);

	// increaase the xp of value
	// check if the player got a new level
	// increase stats in case of level up
	void increaseXpAndCheckForLvlUp(short value);

	// print all player stats
	void printStats() const;

	// set all stats to default
	void resetAllStats();


	const double& getHealth() const { return m_player.hp; }
	const double& getMaxHealth() const { return m_player.maxHp; }
	const double& getAttack() const { return m_player.atk; }

	const short& getLvl() const { return m_player.lvl; }
	const int& getLvlUpXp() const { return m_player.lvlUpXp; }
	const int& getXp() const { return m_player.xp; }

	const short& getCritRate() const { return m_player.critRate; }
	const double& getCritDmg() const { return m_player.critDmg; }
	const std::string_view getName() const { return m_player.name; }

	Inventory& setInventory() { return m_inventory; }


private:

	Player m_player{ };
	Stats m_stats{ };
	Inventory m_inventory{ };

	// increase the stats of the player if he got a new level
	void lvlUp();

};

#endif // !KIIYUO_PLAYERZ_CLASS_H