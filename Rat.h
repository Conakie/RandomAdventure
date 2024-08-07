
#ifndef KIIYUO_RATABS_CREATURES_ENCOUNTER_RAT_CLASS
#define KIIYUO_RATABS_CREATURES_ENCOUNTER_RAT_CLASS

#include "Encounterz.h"
#include "Rat.h"

namespace Creatures
{
    namespace Encounter
    {
        class Rat final : public Encounterz
        {
        public:
            void talk() override;
            void setName() override;
            void setStats() override;
        private:
        };
    }
}
#endif // !KIIYUO_RATABS_CREATURES_ENCOUNTER_RAT_CLASS