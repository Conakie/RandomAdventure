
#ifndef KIIYUO_CONSOLESTYLE_CLASS_H
#define KIIYUO_CONSOLESTYLE_CLASS_H

#include "ConsoleColor.h"
#include "PlaceNames.h"

namespace Console
{
    void setColor(Color color);
    void setColorPerPlace(Places place);

    extern bool isAuto;
}

#endif // !KIIYUO_CONSOLESTYLE_CLASS_H
