
#ifndef KIIYUO_RATABS_CREATURES_ENCOUNTER_GHOST_CLASS
#define KIIYUO_RATABS_CREATURES_ENCOUNTER_GHOST_CLASS

#include "Encounterz.h"
#include "Ghost.h"

namespace Creatures
{
    namespace Encounter
    {
        class Ghost final : public Encounterz
        {
        public:
            void talk() override;
            void thinkAndAct() override;
            void setName() override;
            void setStats() override;
        private:
        };
    }
}
#endif // !KIIYUO_RATABS_CREATURES_ENCOUNTER_GHOST_CLASS
