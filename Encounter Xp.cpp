
#include <iostream>
//#include "Encounter Stats.h"



namespace Encounter
{

	namespace Xp
	{

		int xp(short action, int value, char operation)
		{

			static int s_xp{ 0 };


			switch (action)
			{
			case 0://set

				s_xp = value;

				break;

			case 1://edit

				switch (operation)
				{
				case '+':

					s_xp += value;

					break;

				case '-':

					s_xp -= value;

					break;

				case '*':

					s_xp *= value;

					break;

				case '/':

					s_xp /= value;

					break;

				default:



					break;
				}

				break;

			default:

				break;
			}

			return s_xp;

		}



		void set(int value)
		{

			xp(0, value, ' ');// ' ' is there only because I need to send something

		}



		int get()
		{

			return xp(2, 0, ' ');//0 and ' ' are there only because you need to send something

		}



		void edit(int value, char operation)
		{

			xp(1, value, operation);

		}



		//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\\



		int lvlUpXp(short action, int value, char operation)
		{

			static int s_lvlUpXp{ 0 };


			switch (action)
			{
			case 0://set

				s_lvlUpXp = value;

				break;

			case 1://edit

				switch (operation)
				{
				case '+':

					s_lvlUpXp += value;

					break;

				case '-':

					s_lvlUpXp -= value;

					break;

				case '*':

					s_lvlUpXp *= value;

					break;

				case '/':

					s_lvlUpXp /= value;

					break;

				default:



					break;
				}

				break;

			default:

				break;
			}

			return s_lvlUpXp;

		}



		void setlvlUpXp(int value)
		{

			lvlUpXp(0, value, ' ');// ' ' is there only because I need to send something

		}



		int getlvlUpXp()
		{

			return lvlUpXp(2, 0, ' ');//0 and ' ' are there only because you need to send something

		}



		void editlvlUpXp(int value, char operation)
		{

			lvlUpXp(1, value, operation);

		}

	}

}