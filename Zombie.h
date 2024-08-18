
#ifndef KIIYUO_RATABS_CREATURES_ENCOUNTER_ZOMBIE_CLASS
#define KIIYUO_RATABS_CREATURES_ENCOUNTER_ZOMBIE_CLASS

#include "Encounterz.h"

namespace Creatures
{
    namespace Encounter
    {
        class Zombie final : public Encounterz
        {
        public:
            void talk() override;
            void setName() override;
            void setStats() override;
        private:
            void dialogue();
            void dialogueDidYaKillSkely();
            void dialogueDoyaKnowWhoKilledSkely();
            void dialogueRememberMyName();
            void dialogueRevenge();
        };
    }
}
#endif // !KIIYUO_RATABS_CREATURES_ENCOUNTER_ZOMBIE_CLASS
