
#ifndef KIIYUO_RATABS_CREATURES_ENCOUNTER_SHOTA_CLASS
#define KIIYUO_RATABS_CREATURES_ENCOUNTER_SHOTA_CLASS

#include "Encounterz.h"
#include "Shota.h"

namespace Creatures
{
    namespace Encounter
    {
        class Shota final : public Encounterz
        {
        public:
            void talk() override;
            void setName() override;
            void setStats() override;
        private:
        };
    }
}
#endif // !KIIYUO_RATABS_CREATURES_ENCOUNTER_SHOTA_CLASS
