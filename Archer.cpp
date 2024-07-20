
#include "Archer.h"
#include "Random.h"



namespace Creatures
{
    namespace Player
    {
        void Archer::attack(Encounters& enc)
        {
            std::cout << "You fire an arrow at " << enc.getName() << '\n';
            if (Random::get(0, 99) < critRate)
            {
                std::cout << "You did a critical hit!\n"
                    << enc.getName() << " took " << (atk * critDmg) << "dmg.\n";
                enc.takeDamage(atk * critDmg);
            }
            else
            {
                std::cout << enc.getName() << " took " << (atk) << "dmg.\n";
                enc.takeDamage(atk);
            }
        }

        void Archer::resetAllStats()
        {
            // reset player character stats
            hp = 10;
            maxHp = 10;
            atk = 4;
            maxAtk = 4;
            def = 1;
            maxDef = 1;
            xp = 0;
            lvlUpXp = 22;
            lvl = 1;
            critRate = 9;
            critDmg = 2.5;
            stamina = 80;
            weight = 0;

            // reset stats
            m_stats.strength = -1;
            m_stats.dexterity = -1;
            m_stats.intelligence = -1;
            m_stats.wisdom = -1;
            m_stats.charisma = -1;

            //reset the inventory
            m_inventory.reset();
        }

    };
};