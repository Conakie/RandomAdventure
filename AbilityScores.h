
#ifndef KIIYUO_RATABS_CREATURES_PLAYER_ABILITYSCORES_KLASSE_H
#define KIIYUO_RATABS_CREATURES_PLAYER_ABILITYSCORES_KLASSE_H

#include <ostream>
#include "Costants.h"

namespace Creatures
{
    namespace Player
    {
        class AbilityScores
        {
        public:
            void setStats();
            void reset();

            friend std::ostream& operator<< (const AbilityScores& stats, std::ostream& out);
        protected:
        private:
            short m_strength{ -1 };
            short m_dexterity{ -1 };
            short m_constitution{ -1 };
            short m_intelligence{ -1 };
            short m_wisdom{ -1 };
            short m_charisma{ -1 };

            void rollStats(short arr[k_statsAmount]) const;
            bool checkIfTempStatsAreOk(short arr[k_statsAmount]);
            void assignStats(short arr[k_statsAmount]);
        };
    }
}

#endif // !KIIYUO_RATABS_CREATURES_PLAYER_ABILITYSCORES_KLASSE_H
