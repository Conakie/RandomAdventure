
#include <string_view>
#include <string>
#include "Input.h"
#include "Stats.h"
#include "Playerz.h"
#include "Encounters.h"



Playerz& player()
{

	static Playerz s_giocatore{ };

    return s_giocatore;

}

/*
std::cout << "Short" << sizeof(short) << "\n"
		<< "Int" << sizeof(int) << "\n"
		<< "Double" << sizeof(double) << "\n"
		<< "Long long" << sizeof(long int) << "\n"
		<< "Long double" << sizeof(long double) << "\n"
		<< "\n";
*/

Encounters& encounter()
{

    static Encounters s_incontro{ };

    return s_incontro;

}
//Playerz player{ };
//Encounters encounter{ };