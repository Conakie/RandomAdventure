
#ifndef KIIYUO_CLERIC_CLASS_H
#define KIIYUO_CLERIC_CLASS_H

#include "Playerz.h"
#include "Encounters.h"

namespace Creatures
{
    namespace Player
    {
        class Cleric final : public Playerz
        {
        public:
            // attack a single encounter with a spell
            // or heal an ally/himself
            void attack(Encounters& enc) override;

            // print all the stats the mage and the player has
            void printStats() const override;
            // resets all stats to level 1
            void resetAllStats() override;
        private:
            double useBlessing();
            double useCurse();

            int spiritualEnergy{ 60 };
            int maxSpiritualEnergy{ 60 };
        };
    };
};

#endif // !KIIYUO_CLERIC_CLASS_H