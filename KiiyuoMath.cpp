
#include "KiiyuoMath.h"

double roundToTwoDecimals(double num)
{
    return (double)((int)((num + 0.005) * 100)) / 100;
}
