
#ifndef KIIYUO_RATABS_CREATURES_ENCOUNTER_ENORMOUSRAT_CLASS
#define KIIYUO_RATABS_CREATURES_ENCOUNTER_ENORMOUSRAT_CLASS

#include "Encounterz.h"

namespace Creatures
{
    namespace Encounter
    {
        class EnormousRat final : public Encounterz
        {
        public:
            void talk() override;
            void setName() override;
            void setStats() override;
        private:
        };
    }
}
#endif // !KIIYUO_RATABS_CREATURES_ENCOUNTER_ENORMOUSRAT_CLASS
