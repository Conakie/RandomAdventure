
#ifndef KIIYUO_PLAYERZ_CLASS_H
#define KIIYUO_PLAYERZ_CLASS_H
#define KCA1


#include <iostream>
#include <string_view>
#include "Player Stats.h"
#include "Object UID.h"
#include "Items.h"
#include "Inventory.h"
#include "Costants.h"


#ifndef KNA1

class Encounters;

#endif // !KNA1


class Playerz : protected Players
{
public:
	Playerz() = default;

	// increase the hp of healing or to max hp
	void heal(double healing);

	// attack one encounter
	void virtual attack(Encounters& enc);

	// decrease the player hp
	void takeDamage(double damage);

	// increaase the xp of value
	// check if the player got a new level
	// increase stats in case of level up
	void increaseXpAndCheckForLvlUp(short value);

	// print all player stats
	virtual void printStats() const;

	// set all stats to default
	virtual void resetAllStats();


	const double& getHealth() const { return hp; }
	const double& getMaxHealth() const { return maxHp; }
	const double& getAttack() const { return atk; }

	const short& getLvl() const { return lvl; }
	const int& getLvlUpXp() const { return lvlUpXp; }
	const int& getXp() const { return xp; }

	const short& getCritRate() const { return critRate; }
	const double& getCritDmg() const { return critDmg; }
	const std::string_view getName() const { return name; }

	Inventory& setInventory() { return m_inventory; }
	void setStats();

protected:

	Stats m_stats{ };
	Inventory m_inventory{ };

private:

	// increase the stats of the player if he got a new level
	void lvlUp();
	void rollStats(short arr[k_statsAmount]) const;
	bool checkIfTmpStatsAreOk(short arr[k_statsAmount]) const;
	void assignStats(short arr[k_statsAmount]);
	void applyStatBonus();

};

#endif // !KIIYUO_PLAYERZ_CLASS_H