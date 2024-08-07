#ifndef KIIYUO_RATABS_CREATURES_ENCOUNTER_GIANT_CLASS
#define KIIYUO_RATABS_CREATURES_ENCOUNTER_GIANT_CLASS

#include "Encounterz.h"
#include "Giant.h"

namespace Creatures
{
    namespace Encounter
    {
        class Giant final : public Encounterz
        {
        public:
            void talk() override;
            void setName() override;
            void setStats() override;
        private:
        };
    }
}
#endif // !KIIYUO_RATABS_CREATURES_ENCOUNTER_GIANT_CLASS
