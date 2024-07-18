
#ifndef KIIYUO_ARCHER_CLASS_H
#define KIIYUO_ARCHER_CLASS_H

#include "Playerz.h"
#include "Encounters.h"

class Archer final : public Playerz
{
public:
    // attack one encounter
    void attack(Encounters& enc) override;
    // resets all stats to level 1
    void resetAllStats() override;
private:
};

#endif // !KIIYUO_ARCHER_CLASS_H