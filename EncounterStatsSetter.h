
#ifndef KIIYUO_ENCOUNTER_STATS_SETTER_CLASS_H
#define KIIYUO_ENCOUNTER_STATS_SETTER_CLASS_H

#include "EncounterType.h"
#include "PlacesID.h"
#include "Loot.h"

class EncounterStatsSetter
{
public:
    void set(
        double hp1, double hp2,
        double atk1, double atk2,
        int def,
        int critRate,
        double critDmg,
        int xp,
        int lvl = 1,
        bool isGone = false,
        bool isUnderAttack = false,
        bool canTalk = true
    );
    double getHpMax() const { return m_hp1 + (m_hp2 * m_lvl); }
    double getAtkMax() const { return m_atk1 + (m_atk2 * m_lvl); }
    int getDefMax() const { return m_def; }
    int getCritRate() const { return m_critRate; }
    double getCritDmg() const { return m_critDmg; }
    int getXp() const { return m_xp; }
    int getLvl() const { return m_lvl; }
    bool getIsGone() const { return m_isGone; }
    bool getIsUnderAttack() const { return m_isUnderAttack; }
    bool getCanTalk() const { return m_canTalk; }

private:
    double m_hp1{ 0 };
    double m_hp2{ 0 };
    double m_atk1{ 0 };
    double m_atk2{ 0 };
    int m_def{ 0 };
    int m_critRate{ 0 };
    double m_critDmg{ 0 };
    int m_xp{ 0 };
    int m_lvl{ 1 };
    bool m_isGone{ false };
    bool m_isUnderAttack{ false };
    bool m_canTalk{ true };
};

#endif // !KIIYUO_ENCOUNTER_STATS_SETTER_CLASS_H
