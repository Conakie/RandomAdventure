
#ifndef KIIYUO_SHIELDER_CLASS_H
#define KIIYUO_SHIELDER_CLASS_H

#include "Playerz.h"
#include "Encounters.h"

namespace Creatures
{
    namespace Player
    {
        class Shielder final : public Playerz
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

#endif // !KIIYUO_SHIELDER_CLASS_H