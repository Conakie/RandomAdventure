
#ifndef KIIYOU_RATABS_CREATURES_CREATUREBASE_CLASS_H
#define KIIYOU_RATABS_CREATURES_CREATUREBASE_CLASS_H

#include <string>

namespace Creatures
{
    class CreatureBase
    {
    protected:
        std::string m_name{ "None" };
        double m_hp{ 0 };
        double m_maxHp{ 0 };
        double m_atk{ 0 };
        double m_maxAtk{ 0 };
        double m_critDmg{ 0 };
        int m_critRate{ 0 };
        int m_def{ 0 };
        int m_maxDef{ 0 };
        int m_xp{ 0 };
        int m_xpForLvlUp{ 0 };
        int m_lvl{ 1 };
    };
}

#endif // !KIIYOU_RATABS_CREATURES_CREATUREBASE_CLASS_H