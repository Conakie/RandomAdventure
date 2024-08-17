
#ifndef KIIYUO_RATABS_CREATURES_ENCOUNTER_BARD_CLASS
#define KIIYUO_RATABS_CREATURES_ENCOUNTER_BARD_CLASS

#include "Encounterz.h"

namespace Creatures
{
    namespace Encounter
    {
        class Bard final : public Encounterz
        {
        public:
            void talk() override;
            void thinkAndAct() override;
            void setName() override;
            void setStats() override;
        private:
        };
    }
}
#endif // !KIIYUO_RATABS_CREATURES_ENCOUNTER_BARD_CLASS
