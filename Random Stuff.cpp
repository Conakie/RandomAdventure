
#include <iostream>
#include <windows.h>
#include "Everywhere Used Func.h"
#include "Print Errors.h"
#include "Input.h"



void waitForAnyKey()
{
	std::cout << "\n(Enter any key to continue)\n";
	Input::character();
}



void aspettaPerW()
{

	std::cout << "\n(Premi w per continuare)\n";
	while (Input::character() != 'w')
	{

		std::cout << "\n";

	}

}



void delay(int seconds)
{

	Sleep(seconds * 1000);

}



char convertToChar(int number)
{
	switch (number)
	{
	case 0: return '0';
	case 1: return '1';
	case 2: return '2';
	case 3: return '3';
	case 4: return '4';
	case 5: return '5';
	case 6: return '6';
	case 7: return '7';
	case 8: return '8';
	case 9: return '9';
	default: return '&';
	}
	return '_';
}