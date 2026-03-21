
#include <stdlib.h>
#include "ConsoleStyle.h"
#include "PlacesID.h"

namespace ConsoleStyle
{
    bool autoColor{ false };

    void setColor(int color)
    {
        switch (color)
        {
        case 0:
            system("Color A0");
            break;
        default:
            break;
        }
    }

    void setColorPerPlace(PlacesID place)
    {
        switch (place)
        {
        case PlacesID::dungeon:
            system("Color 07");
            break;
        case PlacesID::village:
            system("Color F0");
            break;
        case PlacesID::cave:
            system("Color 80");
            break;
        case PlacesID::forest:
            system("Color 70");
            break;
        case PlacesID::unknown:
            system("Color 70");
            break;
        default:
            break;
        }
    }

    void setAutoCor(bool autoColor)
    {
        ConsoleStyle::autoColor = autoColor;
    }
}
