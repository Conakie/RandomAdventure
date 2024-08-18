
#ifndef KIIYUO_DIALOGUES_PRISONER_H
#define KIIYUO_DIALOGUES_PRISONER_H

void killOrNot();

#endif // !KIIYUO_DIALOGUES_PRISONER_H


#ifndef KIIYUO_RATABS_CREATURES_ENCOUNTER_PRISONER_CLASS
#define KIIYUO_RATABS_CREATURES_ENCOUNTER_PRISONER_CLASS

#include "Encounterz.h"

namespace Creatures
{
    namespace Encounter
    {
        class Prisoner final : public Encounterz
        {
        public:
            void talk() override;
            void setName() override;
            void setStats() override;
        private:
            void dialogue();
            void dialogueKillOrNot();
        };
    }
}
#endif // !KIIYUO_RATABS_CREATURES_ENCOUNTER_PRISONER_CLASS
