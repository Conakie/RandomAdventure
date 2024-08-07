
#ifndef KIIYUO_DIALOGUES_RATMAN_H
#define KIIYUO_DIALOGUES_RATMAN_H
#include "Encounterz.h"

void requestHelp();

void takeHead();

void fight();

void argue();

#endif // !KIIYUO_DIALOGUES_RATMAN_H

#ifndef KIIYUO_RATABS_CREATURES_ENCOUNTER_RATMAN_CLASS
#define KIIYUO_RATABS_CREATURES_ENCOUNTER_RATMAN_CLASS

#include "Encounterz.h"
#include "Ratman.h"

namespace Creatures
{
    namespace Encounter
    {
        class Ratman final : public Encounterz
        {
        public:
            void talk() override;
            void setName() override;
            void setStats() override;
        private:
        };
    }
}
#endif // !KIIYUO_RATABS_CREATURES_ENCOUNTER_RATMAN_CLASS