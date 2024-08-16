
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
            bool m_isGone         { false };
            bool m_isUnderAttack  { false };
            bool m_canTalk        { true };
            EncounterType encounterType{ EncounterType::none };
        private:
        };
    }
};

#endif // !KIIYUO_RATABS_ENCOUNTERBASE_CLASS_H