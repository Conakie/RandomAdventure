
#ifndef KIIYUO_MAGE_CLASS_H
#define KIIYUO_MAGE_CLASS_H

#include "Playerz.h"
#include "Encounters.h"

class Cleric final : public Playerz
{
public:
    // attack a single encounter with a spell
    // or heal an ally/himself
    void attack(Encounters& enc) override;

    // print all the stats the mage and the player has
    void printStats() const override;
    // resets all stats to level 1
    void resetAllStats() override;
private:
    int useSpell();
    int useBlessing();
    int useCurse();

    int spiritualEnergy{ 60 };
    int maxSpiritualEnergy{ 60 };
};

#endif // !KIIYUO_MAGE_CLASS_H