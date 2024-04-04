
#include <iostream>
#include "Everywhere Used Func.h"



double compare(double a, double b)
{

	static constexpr double epsilon{ 3.01 };
	return fabs(a - b) < epsilon;

}