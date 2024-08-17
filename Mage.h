
#ifndef KIIYUO_MAGE_CLASS_H
#define KIIYUO_MAGE_CLASS_H

#include "Playerz.h"
#include "Encounters.h"

namespace Creatures
{
    namespace Player
    {
        class Mage final : public Playerz
        {
        public:
            void heal(double healing) override;
            // attack a single encounter with a spell
            void attack(Encounters& enc) override;
            // attack a single encounter with a spell
            void virtual attack(Creatures::Encounter::Encounterz& enc);

            // print all the stats the mage and the player has
            void printStats() const override;
            // resets all stats to level 1
            void resetAllStats() override;
        private:
            int useSpell();

            int mana{ 45 };
            int maxMana{ 45 };
        };
    };
};

#endif // !KIIYUO_MAGE_CLASS_H