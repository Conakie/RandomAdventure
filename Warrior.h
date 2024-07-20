
#ifndef KIIYUO_WARRIOR_CLASS_H
#define KIIYUO_WARRIOR_CLASS_H

#include "Playerz.h"
#include "Encounters.h"

namespace Creatures
{
    namespace Player
    {
        class Warrior final : public Playerz
        {
        public:
            // attack one encounter
            void attack(Encounters& enc) override;
            // resets all stats to level 1
            void resetAllStats() override;
        private:
        };
    };
};

#endif // !KIIYUO_WARRIOR_CLASS_H