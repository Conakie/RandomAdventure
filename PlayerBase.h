
#ifndef KIIYUO_RATABS_CREATURES_PLAYER_PLAYERBASE_KLASSE_H
#define KIIYUO_RATABS_CREATURES_PLAYER_PLAYERBASE_KLASSE_H

#include "CreatureBase.h"
#include "PlayerRole.h"
#include "AbilityScores.h"
#include "Inventory.h"

namespace Creatures
{
    namespace Player
    {
        class PlayerBase : public CreatureBase
        {
        public:
        protected:
            PlayerRole m_role{ PlayerRole::none };
            AbilityScores m_abilityScores{ };
            Inventory m_inventory{ };
        };
    }
}

#endif // !KIIYUO_RATABS_CREATURES_PLAYER_PLAYERBASE_KLASSE_H