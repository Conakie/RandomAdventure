#ifndef KIIYUO_RATABS_CREATURES_ENCOUNTER_SOLDIER_CLASS
#define KIIYUO_RATABS_CREATURES_ENCOUNTER_SOLDIER_CLASS

#include "Encounterz.h"
#include "Soldier.h"

namespace Creatures
{
    namespace Encounter
    {
        class Soldier final : public Encounterz
        {
        public:
            virtual void talk();
            virtual void thinkAndAct();
            virtual void printStats() const;
            virtual void resetStats();
            virtual void setName();
            virtual void setStats();
        private:
            int healTurnCooldown{ 1 };
            int lastHealHappenedInTurns{ 0 };
        };
    }
}
#endif // !KIIYUO_RATABS_CREATURES_ENCOUNTER_SOLDIER_CLASS