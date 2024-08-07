
#ifndef KIIYUO_DIALOGUES_YOURSELF_H
#define KIIYUO_DIALOGUES_YOURSELF_H

void dialogue1Part1();

#endif // !KIIYUO_DIALOGUES_YOURSELF_H

#ifndef KIIYUO_RATABS_CREATURES_ENCOUNTER_YOURSELF_CLASS
#define KIIYUO_RATABS_CREATURES_ENCOUNTER_YOURSELF_CLASS

#include "Encounterz.h"
#include "Yourself.h"

namespace Creatures
{
    namespace Encounter
    {
        class Yourself final : public Encounterz
        {
        public:
            void talk() override;
            void setName() override;
            void setStats() override;
        private:
        };
    }
}
#endif // !KIIYUO_RATABS_CREATURES_ENCOUNTER_YOURSELF_CLASS
