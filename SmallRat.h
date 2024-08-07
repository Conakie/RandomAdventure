
#ifndef KIIYUO_RATABS_CREATURES_ENCOUNTER_SMALLRAT_CLASS
#define KIIYUO_RATABS_CREATURES_ENCOUNTER_SMALLRAT_CLASS

#include "Encounterz.h"
#include "SmallRat.h"

namespace Creatures
{
    namespace Encounter
    {
        class SmallRat final : public Encounterz
        {
        public:
            void talk() override;
            void setName() override;
            void setStats() override;
        private:
        };
    }
}
#endif // !KIIYUO_RATABS_CREATURES_ENCOUNTER_SMALLRAT_CLASS