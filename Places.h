
#ifndef KIIYUO_PLACES_CLASS_H
#define KIIYUO_PLACES_CLASS_H

#include "PlacesID.h"

class Places
{
public:
    Places() = default;

    PlacesID generatePlace();
    void printPlace() const;

    PlacesID getLocation() const { return m_location; }
    LightAmount getLightLevel() const { return m_lightLevel; }
private:
    void generateLocation();
    void generateRoom();
    void printDungeon() const;
    void printVillage() const;
    void printCave() const;
    void printForest() const;
    void printStronghold() const;
    void printUnknown() const;

    PlacesID m_location{ PlacesID::unknown };
    LightAmount m_lightLevel{ LightAmount::medium };
    int m_roomID{ 0 };
    int m_placeSizeInTurns{ 0 };
    bool m_justEntered{ true };
};

#endif // !KIIYUO_PLACES_CLASS_H