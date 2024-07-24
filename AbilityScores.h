
#ifndef KIIYUO_RATABS_PLAYER_ABILITYSCORES_CLASS_H
#define KIIYUO_RATABS_PLAYER_ABILITYSCORES_CLASS_H

#include <ostream>
#include "Costants.h"


namespace Creatures
{
    namespace Player
    {
        class AbilityScores
        {
        public:
            void reset();
            void setStats();
            void print() const;

            friend std::ostream& operator<< (std::ostream out, AbilityScores& stats);
        private:
            void rollStats(short arr[k_statsAmount]) const;
            bool checkIfTmpStatsAreOk(short arr[k_statsAmount]) const;
            void assignStats(short arr[k_statsAmount]);

            short strength{ 0 };
            short dexterity{ 0 };
            short constitution{ 0 };
            short intelligence{ 0 };
            short wisdom{ 0 };
            short charisma{ 0 };
        };
    };
};

#endif // !KIIYUO_RATABS_PLAYER_ABILITYSCORES_CLASS_H