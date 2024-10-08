
#ifndef KIIYUO_RATABS_CREATURES_ENCOUNTER_DWARF_CLASS
#define KIIYUO_RATABS_CREATURES_ENCOUNTER_DWARF_CLASS

#include "Encounterz.h"

namespace Creatures
{
    namespace Encounter
    {
        class Dwarf final : public Encounterz
        {
        public:
            void talk() override;
            void setName() override;
            void setStats() override;
        private:
            void dialogue();
            void dialogueJoinMe();
        };
    }
}
#endif // !KIIYUO_RATABS_CREATURES_ENCOUNTER_DWARF_CLASS
