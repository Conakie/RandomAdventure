
#ifndef KIIYUO_RATABS_CREATURES_ENCOUNTER_GOBLIN_CLASS
#define KIIYUO_RATABS_CREATURES_ENCOUNTER_GOBLIN_CLASS

#include "Encounterz.h"

namespace Creatures
{
    namespace Encounter
    {
        class Goblin final : public Encounterz
        {
        public:
            void talk() override;
            void setName() override;
            void setStats() override;
        private:
            void dialogue();
            void dialogueScared();
        };
    }
}
#endif // !KIIYUO_RATABS_CREATURES_ENCOUNTER_GOBLIN_CLASS
