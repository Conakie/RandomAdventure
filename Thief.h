
#ifndef KIIYUO_THIEF_CLASS_H
#define KIIYUO_THIEF_CLASS_H

#include "Playerz.h"
#include "Encounters.h"

namespace Creatures
{
    namespace Player
    {
        class Thief final : public Playerz
        {
        public:
            // attack one encounter
            void attack(Encounters& enc) override;
            // attack one encounter
            void virtual attack(Creatures::Encounter::Encounterz& enc);
            // print all the stats the mage and the player has
            void printStats() const override;
            // resets all stats to level 1
            void resetAllStats() override;
        private:
            int stealthHitChance{ 40 };
            double steathDmgBonus{ 2.5 };
        };
    };
};

#endif // !KIIYUO_THIEF_CLASS_H