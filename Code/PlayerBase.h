
#ifndef KIIYUO_RATABS_PLAYERBASE_CLASS_H
#define KIIYUO_RATABS_PLAYERBASE_CLASS_H

#include "CreatureBase.h"
#include "PlayerRole.h"
#include "AbilityScores.h"
#include "Inventory.h"


namespace Creatures
{
    namespace Player
    {
        class PlayerBase : public Creatures::CreatureBase
        {
        public:
            int stamina         { 0 };
            int weight          { 0 };
            PlayerRole role     { PlayerRole::none };
            AbilityScores stats { };
            Inventory inventory { };
        private:

        };
    }
}

#endif // !KIIYUO_RATABS_PLAYERBASE_CLASS_H
