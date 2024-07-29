
#ifndef KIIYUO_RATABS_ENCOUNTERBASE_CLASS_H
#define KIIYUO_RATABS_ENCOUNTERBASE_CLASS_H

#include "CreatureBase.h"
#include "EncounterType.h"

namespace Creatures
{
    namespace Encounter
    {
        class EncounterBase : public CreatureBase
        {
        public:
            bool isGone         { false };
            bool isUnderAttack  { false };
            bool canTalk        { true };
            EncounterType encounterType{ EncounterType::none };
        private:
        };
    }
};

#endif // !KIIYUO_RATABS_ENCOUNTERBASE_CLASS_H