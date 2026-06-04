
#include "EncounterStatsSetter.h"
#include "Random.h"

void EncounterStatsSetter::set(double hp1, double hp2, double atk1, double atk2, int def,
    int critRate, double critDmg, int xp, int lvl, bool isGone, bool isUnderAttack, bool canTalk)
{
    m_hp1 = hp1;
    m_hp2 = hp2;
    m_atk1 = atk1;
    m_atk2 = atk2;
    m_def = def;
    m_critRate = critRate;
    m_critDmg = critDmg;
    m_xp = xp;
    m_lvl = lvl + Random::get(-1, 1);
    m_isGone = isGone;
    m_isUnderAttack = isUnderAttack;
    m_canTalk = canTalk;
}
