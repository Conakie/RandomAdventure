
#ifndef KIIYUO_RATABS_CREATURES_ENCOUNTER_COLOSSALRAT_CLASS
#define KIIYUO_RATABS_CREATURES_ENCOUNTER_COLOSSALRAT_CLASS

#include "Encounterz.h"
#include "ColossalRat.h"

namespace Creatures
{
    namespace Encounter
    {
        class ColossalRat final : public Encounterz
        {
        public:
            void talk() override;
            void setName() override;
            void setStats() override;
        private:
        };
    }
}
#endif // !KIIYUO_RATABS_CREATURES_ENCOUNTER_COLOSSALRAT_CLASS