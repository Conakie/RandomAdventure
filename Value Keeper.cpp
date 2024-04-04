
#include <iostream>
#include "Everywhere Used Func.h"



int intValuekeeper(int value, bool edit)
{

	static int s_value{ 0 };

	if (edit)
	{

		s_value = value;

	}
	else
	{

	}
	
	return s_value;

}



double doubleValueKeeper(double value, bool edit)
{

	static double s_value{ 0.0 };

	if (edit)
	{

		s_value = value;

	}
	else
	{

	}

	return s_value;

}



bool boolValueKeeper(bool value, bool edit)
{

	static bool s_value{ false };

	if (edit)
	{

		s_value = value;

	}
	else
	{

	}

	return s_value;

}