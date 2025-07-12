
#ifndef KIIYUO_RATABS_CREATURES_ENCOUNTERZ_CLASSE_H
#define KIIYUO_RATABS_CREATURES_ENCOUNTERZ_CLASSE_H

#include <string_view>
#include "EncounterBase.h"

namespace Creatures
{
    namespace Player
    {
        class Playerz;
    }
    namespace Encounter
    {
        class Encounterz : public EncounterBase
        {
        public:
            void attack(Player::Playerz& player);
            void heal(double healing);
            void takeDamage(double damage);
            void talk();
            void thinkAndAct();
            void dropItems();

            void resetEncounter();
            bool isAlive() const { return (m_hp > 0.01); }

            void setEncounter();
            void setType(EncounterType type = EncounterType::none);
            void setLvl(int lvl);
            void setPlayer(Player::Playerz* player);

            double getHealth() const { return m_hp; }
            std::string_view getName() const { return m_name; }
        protected:
            virtual void dialogue();
        };
    }
}

#endif // !KIIYUO_RATABS_CREATURES_ENCOUNTERZ_CLASSE_H