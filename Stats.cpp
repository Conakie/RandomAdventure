
#include <string_view>
#include <string>
#include "Input.h"
#include "Stats.h"
#include "Playerz.h"
#include "Encounters.h"
#include "Mage.h"
#include "Shielder.h"
#include "Berserker.h"
#include "Thief.h"



Playerz& player()
{
	static Thief s_giocatore{ };

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

    static Encounters s_encounter{ };

    return s_encounter;

}
//Playerz player{ };
//Encounters encounter{ };