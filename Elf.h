
#ifndef KIIYUO_RATABS_CREATURES_ENCOUNTER_ELF_CLASS
#define KIIYUO_RATABS_CREATURES_ENCOUNTER_ELF_CLASS

#include "Encounterz.h"
#include "Elf.h"

namespace Creatures
{
    namespace Encounter
    {
        class Elf final : public Encounterz
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
#endif // !KIIYUO_RATABS_CREATURES_ENCOUNTER_ELF_CLASS
