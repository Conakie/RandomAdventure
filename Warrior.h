
#ifndef KIIYUO_WARRIOR_CLASS_H
#define KIIYUO_WARRIOR_CLASS_H

#include "Playerz.h"
#include "Encounters.h"

class Warrior final : public Playerz
{
public:
    // attack one encounter
    void attack(Encounters& enc) override;
private:
    
};

#endif // !KIIYUO_WARRIOR_CLASS_H