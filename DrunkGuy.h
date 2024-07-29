#ifndef KIIYUO_RATABS_CREATURES_ENCOUNTER_DRUNKGUY_CLASS
#define KIIYUO_RATABS_CREATURES_ENCOUNTER_DRUNKGUY_CLASS

#include "Encounterz.h"
#include "DrunkGuy.h"

namespace Creatures
{
    namespace Encounter
    {
        class DrunkGuy final : public Encounterz
        {
        public:
            virtual void attack(Creatures::Player::Playerz& player);
            virtual void talk();
            virtual void setName();
            virtual void setStats();
        private:
        };
    }
}
#endif // !KIIYUO_RATABS_CREATURES_ENCOUNTER_DRUNKGUY_CLASS
