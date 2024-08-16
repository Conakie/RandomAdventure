
#ifndef KIIYUO_RATABS_CREATURES_ENCOUNTER_GUARD_CLASS
#define KIIYUO_RATABS_CREATURES_ENCOUNTER_GUARD_CLASS

#include "Encounterz.h"

namespace Creatures
{
    namespace Encounter
    {
        class Guard final : public Encounterz
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
            void dialogueRefuse();
            void dialogueRunAway();
            int healAmount{ 1 };
        };
    }
}
#endif // !KIIYUO_RATABS_CREATURES_ENCOUNTER_GUARD_CLASS