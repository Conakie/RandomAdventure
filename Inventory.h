
#ifndef KIIYUO_INVENTORY_CLASS
#define KIIYUO_INVENTORY_CLASS

#include "Object UID.h"
#include "Items.h"

class Inventory
{
public:

    // set item to value
    void setItem(ObjectUid item, int value = 0);

    // adds to item value
    void addItem(ObjectUid item, int value = 1);

    // set all members to 0
    void reset();

    // true when the function fails to use an item, false otherwise
    // use an item as many times quantity says
    bool useItem(ObjectUid item, int quantity = 1);

    // print all members
    void print() const;

    // get a single item
    const Items& getItem() const { return m_items; }

private:

    Items m_items{ };

};

#endif // !KIIYUO_INVENTORY_CLASS