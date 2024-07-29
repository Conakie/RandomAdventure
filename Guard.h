
#ifndef KIIYUO_RATABS_CREATURES_ENCOUNTER_GUARD_CLASS
#define KIIYUO_RATABS_CREATURES_ENCOUNTER_GUARD_CLASS

#include "Encounterz.h"
#include "Guard.h"

namespace Creatures
{
    namespace Encounter
    {
        class Guard final : public Encounterz
        {
        public:
            virtual void talk();
            virtual void thinkAndAct();
            virtual void printStats() const;
            virtual void resetStats();
            virtual void setName();
            virtual void setStats();
        private:
            int healAmount{ 1 };
        };
    }
}
#endif // !KIIYUO_RATABS_CREATURES_ENCOUNTER_GUARD_CLASS