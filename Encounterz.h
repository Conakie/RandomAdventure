
#ifndef KIIYUO_RATABS_CREATURES_ENCOUNTERZ_CLASSE_H
#define KIIYUO_RATABS_CREATURES_ENCOUNTERZ_CLASSE_H

#include <string_view>
#include "EncounterBase.h"
#include "EncounterStatsSetter.h"
#include "EncounterType.h"

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
            void printStats() const;
            bool isGone() const { return m_isGone; }

            void setEncounter(int lvl);
            void setType(EncounterType type = EncounterType::none);
            void setPlayer(Player::Playerz* player);

            double getHealth() const { return m_hp; }
            std::string_view getName() const { return m_name; }
            std::string_view getIntro() const;
            std::string_view getOutro() const;
        protected:
            void setName(std::string_view name) { m_name = name; }
            void copyStats(EncounterStatsSetter& base);
            virtual void dialogue();
            void setNameFromType();
        };
    }
}

#endif // !KIIYUO_RATABS_CREATURES_ENCOUNTERZ_CLASSE_H