
#ifndef KIIYUO_DIALOGUES_WITH_BARTENDER_H
#define KIIYUO_DIALOGUES_WITH_BARTENDER_H

void roomPlease();

void foodPlease();

void questions();

void takeAway();

void eatAtTable();

#endif // !KIIYUO_DIALOGUES_WITH_BARTENDER_H

#ifndef KIIYUO_RATABS_CREATURES_ENCOUNTER_BARTENDER_CLASS
#define KIIYUO_RATABS_CREATURES_ENCOUNTER_BARTENDER_CLASS

#include "Encounterz.h"
#include "Bartender.h"

namespace Creatures
{
    namespace Encounter
    {
        class Bartender final : public Encounterz
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
#endif // !KIIYUO_RATABS_CREATURES_ENCOUNTER_BARTENDER_CLASS