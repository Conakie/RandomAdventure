
#ifndef KIIYUO_MAGE_CLASS_H
#define KIIYUO_MAGE_CLASS_H

#include "Playerz.h"
#include "Encounters.h"

class Mage final : public Playerz
{
public:
    // attack a single encounter with a spell
    void attack(Encounters enc) const override;

    // print all the stats the mage and the player has
    void printStats() const override;
    // resets all stats to level 1
    void resetAllStats() override;
private:
    int useSpell() const;
    int mana   { 100 };
    int maxMana{ 100 };
};

#endif // !KIIYUO_MAGE_CLASS_H