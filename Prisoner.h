
#ifndef KIIYUO_DIALOGUES_PRISONER_H
#define KIIYUO_DIALOGUES_PRISONER_H

void killOrNot();

#endif // !KIIYUO_DIALOGUES_PRISONER_H


#ifndef KIIYUO_RATABS_CREATURES_ENCOUNTER_PRISONER_CLASS
#define KIIYUO_RATABS_CREATURES_ENCOUNTER_PRISONER_CLASS

#include "Encounterz.h"
#include "Prisoner.h"

namespace Creatures
{
    namespace Encounter
    {
        class Prisoner final : public Encounterz
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
#endif // !KIIYUO_RATABS_CREATURES_ENCOUNTER_PRISONER_CLASS