
#ifndef KIIYUO_RATABS_CREATURE_BASE_CLASS_H
#define KIIYUO_RATABS_CREATURE_BASE_CLASS_H

#include <string>

namespace Creatures
{
    class CreatureBase
    {
    public:
        CreatureBase() = default;

        std::string name{ "None" };
        double hp{ 0.00 };
        double maxHp{ 0.00 };
        double atk{ 0.00 };
        double maxAtk{ 0.00 };
        double critDmg{ 0.00 };
        int critRate{ 0 };
        int def{ 0 };
        int maxDef{ 0 };
        int xp{ 0 };
        int xpPerLvl{ 0 };
        int lvl{ 0 };
    private:

    };
};

#endif // !KIIYUO_RATABS_CREATURE_BASE_CLASS_H