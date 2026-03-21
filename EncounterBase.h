
#ifndef KIIYUO_RATABS_CREATURES_ENCOUNTER_ENCOUNTERBASE_CLASSE_H
#define KIIYUO_RATABS_CREATURES_ENCOUNTER_ENCOUNTERBASE_CLASSE_H

#include <string>
#include "CreatureBase.h"
#include "EncounterType.h"

namespace Creatures
{
    namespace Player
    {
        class Playerz;
    }
    namespace Encounter
    {
        class EncounterBase : public CreatureBase
        {
        public:
        protected:
            Player::Playerz* m_player{ nullptr };
            EncounterType m_type{ EncounterType::none };
            bool m_isGone{ false };
            bool m_isUnderAttack{ false };
            bool m_canTalk{ true };
        };
    }
}

#endif // !KIIYUO_RATABS_CREATURES_ENCOUNTER_ENCOUNTERBASE_CLASSE_H