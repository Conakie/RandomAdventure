
#ifndef KIIYUO_RATABS_CREATURES_ENCOUNTER_DWARF_CLASS
#define KIIYUO_RATABS_CREATURES_ENCOUNTER_DWARF_CLASS

#include "Encounterz.h"
#include "Dwarf.h"

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
        };
    }
}
#endif // !KIIYUO_RATABS_CREATURES_ENCOUNTER_DWARF_CLASS