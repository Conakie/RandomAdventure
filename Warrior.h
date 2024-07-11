
#ifndef KIIYUO_WARRIOR_CLASS_H
#define KIIYUO_WARRIOR_CLASS_H

#include "Playerz.h"
#include "Encounters.h"

class Warrior final : public Playerz
{
public:
    void attack(Encounters enc) const override;
private:
    int mana{ 100 };
};

#endif // !KIIYUO_WARRIOR_CLASS_H