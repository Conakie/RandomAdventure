
#include "EncounterStatsSetter.h"

void EncounterStatsSetter::set(double hp1, double hp2, double atk1, double atk2, int def, int critRate, int critDmg, int xp, int lvl, bool isGone, bool isUnderAttack, bool canTalk)
{
    m_hp1 = hp1;
    m_hp2 = hp2;
    m_atk1 = atk1;
    m_atk2 = atk2;
    m_def = def;
    m_critRate = critRate;
    m_critDmg = critDmg;
    m_xp = xp;
    m_lvl = lvl;
    m_isGone = isGone;
    m_isUnderAttack = isUnderAttack;
    m_canTalk = canTalk;
}
