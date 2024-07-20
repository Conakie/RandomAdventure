
#ifndef KIIYUO_BARBARIAN_CLASS_H
#define KIIYUO_BARBARIAN_CLASS_H

#include "Playerz.h"
#include "Encounters.h"

namespace Creatures
{
    namespace Player
    {
        class Barbarian final : public Playerz
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
            int oneShotChance{ 10 };
        };
    };
};

#endif // !KIIYUO_BARBARIAN_CLASS_H