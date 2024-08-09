
#ifndef KIIYUO_RATABS_CREATURES_ENCOUNTER_STONEGOLEM_CLASS
#define KIIYUO_RATABS_CREATURES_ENCOUNTER_STONEGOLEM_CLASS

#include "Encounterz.h"

namespace Creatures
{
    namespace Encounter
    {
        class StoneGolem final : public Encounterz
        {
        public:
            void talk() override;
            void setName() override;
            void setStats() override;
        private:
        };
    }
}
#endif // !KIIYUO_RATABS_CREATURES_ENCOUNTER_STONEGOLEM_CLASS