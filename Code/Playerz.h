
#ifndef KIIYUO_PLAYERZ_CLASS_H
#define KIIYUO_PLAYERZ_CLASS_H
#define KCA1


#include <iostream>
#include <string_view>
#include <string>
#include "Encounterz.h"
#include "Player Stats.h"
#include "PlayerBase.h"
#include "Inventory.h"
#include "Object UID.h"
#include "Items.h"
#include "Inventory.h"
#include "Costants.h"


#ifndef KNA1

class Encounters;

#endif // !KNA1

#ifndef KIIYUO_RATABS_CREATURES_ENCOUNTER_ENCOUNTERZ_CLASS_H

namespace Creatures
{
	namespace Encounter
	{
		class Encounterz;
	};
};

#endif // !KIIYUO_RATABS_CREATURES_ENCOUNTER_ENCOUNTERZ_CLASS_H


namespace Creatures
{
	namespace Player
	{
		class Playerz : protected PlayerBase
		{
		public:
			Playerz() = default;

			// increase the hp of healing or to max hp
			void virtual heal(double healing);

			// attack one encounter
			void virtual attack(Encounters& enc);
			// attack one encounter
			void virtual attack(Creatures::Encounter::Encounterz& enc);

			// decrease the player hp
			void takeDamage(double damage);

			// increaase the xp of value
			// check if the player got a new level
			// increase stats in case of level up
			void increaseXpAndCheckForLvlUp(short value);

			// print all player stats
			virtual void printStats() const;

			// returns true if the player is alive, false otherwise
			bool isAlive() const { return (hp > 0.00); }

			// set all stats to default
			virtual void resetAllStats();


			const double& getHealth() const { return hp; }
			const double& getMaxHealth() const { return maxHp; }
			const double& getAttack() const { return atk; }

			const int& getLvl() const { return lvl; }
			const int& getLvlUpXp() const { return xpPerLvl; }
			const int& getXp() const { return xp; }

			const int& getCritRate() const { return critRate; }
			const double& getCritDmg() const { return critDmg; }
			const std::string_view getName() const { return name; }

			Inventory& setInventory() { return inventory; }
			void setStats();
			void setName(std::string newName);

		private:
			// increase the stats of the player if he got a new level
			void lvlUp();
			void applyStatBonus();

		};
	};
};


#endif // !KIIYUO_PLAYERZ_CLASS_H
