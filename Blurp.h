
#ifndef KIIYUO_RATABS_CREATURES_ENCOUNTER_BLURP_CLASS
#define KIIYUO_RATABS_CREATURES_ENCOUNTER_BLURP_CLASS

#include "Encounterz.h"

namespace Creatures
{
    namespace Encounter
    {
        class Blurp final : public Encounterz
        {
        public:
            void talk() override;
            void setName() override;
            void setStats() override;
        private:
        };
    }
}
#endif // !KIIYUO_RATABS_CREATURES_ENCOUNTER_BLURP_CLASS