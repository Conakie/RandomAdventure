
#ifndef KIIYUO_RATABS_CREATURES_ENCOUNTER_SOLDIER_CLASS
#define KIIYUO_RATABS_CREATURES_ENCOUNTER_SOLDIER_CLASS

#include "Encounterz.h"

namespace Creatures
{
    namespace Encounter
    {
        class Soldier final : public Encounterz
        {
        public:
            void talk() override;
            void thinkAndAct() override;
            void printStats() const override;
            void resetStats() override;
            void setName() override;
            void setStats() override;
        private:
            void dialogue();
            int healTurnCooldown{ 1 };
            int lastHealHappenedInTurns{ 0 };
        };
    }
}
#endif // !KIIYUO_RATABS_CREATURES_ENCOUNTER_SOLDIER_CLASS
