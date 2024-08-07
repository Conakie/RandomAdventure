
#ifndef KIIYUO_RATABS_CREATURES_ENCOUNTER_THEBEER_CLASS
#define KIIYUO_RATABS_CREATURES_ENCOUNTER_THEBEER_CLASS

#include "Encounterz.h"
#include "TheBeer.h"

namespace Creatures
{
    namespace Encounter
    {
        class TheBeer final : public Encounterz
        {
        public:
            void talk() override;
            void setName() override;
            void setStats() override;
        private:
        };
    }
}
#endif // !KIIYUO_RATABS_CREATURES_ENCOUNTER_THEBEER_CLASS
