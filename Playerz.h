
#ifndef KIIYUO_RATABS_CREATURES_PLAYER_PLAYERZ_KLASSE_H
#define KIIYUO_RATABS_CREATURES_PLAYER_PLAYERZ_KLASSE_H

#include <string_view>
#include "CreatureBase.h"
#include "PlayerBase.h"

namespace Creatures
{
    namespace Encounter
    {
        class Encounterz;
    }

    namespace Player
    {
        class Playerz : public PlayerBase
        {
        public:
            void attack(Encounter::Encounterz& encounter);
            void heal(double healing);
            void takeDamage(double damage);
            void talk();
            Inventory& openInventory() { return m_inventory; }

            void resetPlayer();
            bool isAlive() const { return (m_hp >= 0.01); }
            void printPlayerStats() const;

            void setRole(PlayerRole role = PlayerRole::narrator);
            void setAbilityScores();
            void setPlayer(PlayerRole role = PlayerRole::narrator, std::string_view name = "You");
            void silentSetPlayer(PlayerRole role = PlayerRole::narrator, std::string_view name = "You");
            int getLvl() const { return m_lvl; }
            double getHealth() const { return m_hp; }
            double getMaxHealth() const { return m_maxHp; }
            std::string_view getName() const { return m_name; }
        protected:
        };
    }
}

#endif // !KIIYUO_RATABS_CREATURES_PLAYER_PLAYERZ_KLASSE_H