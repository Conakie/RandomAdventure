
#ifndef KIIYUO_RATABS_CREATURES_ENCOUNTER_KOBOLD_CLASS
#define KIIYUO_RATABS_CREATURES_ENCOUNTER_KOBOLD_CLASS

#include "Encounterz.h"

namespace Creatures
{
    namespace Encounter
    {
        class Kobold final : public Encounterz
        {
        public:
            void talk() override;
            void setName() override;
            void setStats() override;
        private:
            void dialogue();
        };
    }
}
#endif // !KIIYUO_RATABS_CREATURES_ENCOUNTER_KOBOLD_CLASS
