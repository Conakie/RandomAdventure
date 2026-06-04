
#ifndef KIIYUO_RATABS_ITEMS_CLASS_H
#define KIIYUO_RATABS_ITEMS_CLASS_H

namespace Items
{
    class Items final
    {
    public:
        long int cota{ 0 };
        int smallHealingPotion{ 0 };
        int mediumHealingPotion{ 0 };
        int bigHealingPotion{ 0 };
        int molotov{ 0 };
        int nuke{ 0 };
        int herbs{ 0 };
        int wood{ 0 };
        int arrow{ 0 };
        int leather{ 0 };
        int stone{ 0 };
        int bone{ 0 };
        int paper{ 0 };
        int meat{ 0 };
        int fish{ 0 };// not Kokomi
        int mushroom{ 0 };
        int magicScroll{ 0 };
    private:
    };

    enum class ItemName
    {
        cota,
        smallHealingPotion,
        mediumHealingPotion,
        bigHealingPotion,
        molotov,
        nuke,
        herbs,
        wood,
        arrow,
        leather,
        stone,
        bone,
        paper,
        meat,
        fish,
        mushroom,
        magicScroll,
        none,
    };
}

#endif // !KIIYUO_RATABS_ITEMS_CLASS_H