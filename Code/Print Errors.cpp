
#include <iostream>
#include "Print Errors.h"



namespace PrintError
{
	void printPleaseReport()
	{
		std::cout << "Please report this to Nanre.\n"
			<< "Also if you can add a screenshot it would be of help.\n"
			<< "This will make OUR game better!\n";
	}

	void notFound()
	{
		std::cout << "\nError 000: Not found!\n";
		PrintError::printPleaseReport();
	}

	void wrongRandomNumber()
	{
		std::cout << "\nError 001: Random number too high or too low!\n";
		PrintError::printPleaseReport();
	}

	void wrongNumber()
	{
		std::cout << "\nError 002: A number did not match any case in a funcion!\n";
		PrintError::printPleaseReport();
	}

	void actionNotFound()
	{
		std::cout << "\nError 003: Action not found.\n";
		PrintError::printPleaseReport();
	}

	void playerNotFound()
	{
		std::cout << "\nError 004: Player not set.\n";
		PrintError::printPleaseReport();
	}
}
