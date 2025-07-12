
#ifndef KIIYUO_RATABS_CREATURE_PLAYER_PLAYER_INVENTORY_CLASS_H
#define KIIYUO_RATABS_CREATURE_PLAYER_PLAYER_INVENTORY_CLASS_H

#include <string_view>
#include "Items.h"

namespace Creatures
{
    namespace Encounter
    {
        class Encounterz;
    }
    namespace Player
    {
        class Playerz;

        class Inventory final
        {
        public:
            bool useItem(Items::ItemName item, int quantity = 1);
            void addItem(Items::ItemName item, int quantity = 1);
            void printAndAdd(Items::ItemName item, int quantity = 1);
            void reset();

            void setTarget(Playerz* player);
            void setTarget(Encounter::Encounterz* encounter);
        private:
            Items::Items m_items{ };
            Playerz* m_player{ nullptr };
            Encounter::Encounterz* m_encounter{ nullptr };

            bool isTheQuantityOk(int* item, int quantity) const;
            void printInsufficientItems() const;
            void printMessage(std::string_view message) const;
        };
    }
}

#endif // !KIIYUO_RATABS_CREATURE_PLAYER_PLAYER_INVENTORY_CLASS_H