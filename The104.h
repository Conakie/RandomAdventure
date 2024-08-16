
#ifndef KIIYUO_RATABS_CREATURES_ENCOUNTER_THE104_CLASS
#define KIIYUO_RATABS_CREATURES_ENCOUNTER_THE104_CLASS

#include "Encounterz.h"

namespace Creatures
{
    namespace Encounter
    {
        class The104 final : public Encounterz
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
#endif // !KIIYUO_RATABS_CREATURES_ENCOUNTER_THE104_CLASS
