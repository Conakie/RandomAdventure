
#ifndef KIIYUO_ENCOUNTERS_CLASS_H
#define KIIYUO_ENCOUNTERS_CLASS_H
#define KNA1


#include <iostream>
#include <string_view>
#include "Encounter Stats.h"
#include "Encounter UID.h"


#ifndef KCA1

namespace Creatures
{
    namespace Player
    {
        class Playerz;
    };
};

#endif // !KCA1


class Encounters
{
public:
    Encounters() = default;

    // increase the hp of healing but if it is higher then the max hp
    // the encounter will be back to max health
    void heal(double healing);

    // decrease hp of damage. If the encounter dies, the player will be notified
    void takeDamage(double damage);

    void attack(Creatures::Player::Playerz& ally) const;

    // increase the xp of value. Also checks for lvl up.
    void increaseXp(short value);

    // set a new encounter with all its stats + notify the player
    void setEncounter();

    // drop a maximum of 3 items of the same type using a set drop rate
    void dropItems();

    // returns the name of the encounter
    std::string_view getName() const;

    void thinkAndAct();
    // print all the stats
    void printStats() const;

    bool isAlive() const{ return (m_encounter.hp > 0.00); }

    // set all stats to default
    void resetAllStats();

    const double& getHealth() const { return m_encounter.hp; }
    const double& getAttack() const { return m_encounter.atk; }
    const EncounterUid& getUid() const { return m_encounter.uid; }

    const bool& getCanTalk() const { return m_encounter.canTalk; }
    const bool& getIsUnderAttack() const { return m_encounter.isUnderAttack; }
    const bool& getIsGone() const { return m_encounter.isGone; }

    const short& getLvl() const { return m_encounter.lvl; }

    void setCanTalk(bool canTalk) { m_encounter.canTalk = canTalk; }
    void setIsUnderAttack(bool isUnderAttack) { m_encounter.isUnderAttack = isUnderAttack; }
    void setIsGone(bool isGone) { m_encounter.isGone = isGone; }

    void setUid(EncounterUid uid) { m_encounter.uid = uid; }

private:

    Encounter m_encounter{ };
    
    void lvlUp();

    void setState();

    void setStats();

    void introduceEncounter();

};

#endif // !KIIYUO_ENCOUNTERS_CLASS_H
