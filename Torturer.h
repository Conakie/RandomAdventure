
#ifndef KIIYUO_RATABS_CREATURES_ENCOUNTER_TORTURER_CLASS
#define KIIYUO_RATABS_CREATURES_ENCOUNTER_TORTURER_CLASS

#include "Encounterz.h"
#include "Torturer.h"

namespace Creatures
{
    namespace Encounter
    {
        class Torturer final : public Encounterz
        {
        public:
            void talk() override;
            void setName() override;
            void setStats() override;
        private:
        };
    }
}
#endif // !KIIYUO_RATABS_CREATURES_ENCOUNTER_TORTURER_CLASS
