
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
            void attack(Creatures::Player::Playerz& player) override;
            void talk() override;
            void setName() override;
            void setStats() override;
        private:
        };
    }
}
#endif // !KIIYUO_RATABS_CREATURES_ENCOUNTER_DRUNKGUY_CLASS
