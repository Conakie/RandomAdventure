
#include <Windows.h>
#include <iostream>
#include "ConsoleStyle.h"
#include "ConsoleColor.h"
#include "Place.h"


namespace Console
{
	bool isAuto{ false };



	void setColor(Color color)
	{
		// change the color of the console
		switch (color)
		{
		case Color::light:
			system("Color 70");
			break;
		case Color::dark:
			system("Color 07");
			break;
		case Color::hacker:
			system("Color 0A");
			break;
		case Color::dungeon:
			system("Color 81");
			break;
		case Color::talk:
			system("Color 85");
			break;
		default:
			break;
		}

	}



	void setColorPerPlace(Places place)
	{
		// if the @isAuto is true then change the color based on the place
		// or if @isAuto is false don't change anything
		if (isAuto)
		{
			switch (place)
			{
			case Places::village:
				setColor(Color::light);
				break;
			case Places::dungeon:
				setColor(Color::dungeon);
				break;
			case Places::cave:
				setColor(Color::dark);
				break;
			case Places::forest:
				setColor(Color::dungeon);
				break;
			default:
				setColor(Color::hacker);
				break;
			}
		}
		else
		{

		}

	}

}
