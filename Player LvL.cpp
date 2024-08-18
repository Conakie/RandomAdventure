
#include <iostream>
//#include "Player Stats.h"



namespace Player
{

	namespace Lvl
	{

		int lvl(short action, int value, char operation)
		{

			static int s_lvl{ 0 };


			switch (action)
			{
			case 0://set

				s_lvl = value;

				break;

			case 1://edit

				switch (operation)
				{
				case '+':

					s_lvl += value;

					break;

				case '-':

					s_lvl -= value;

					break;

				case '*':

					s_lvl *= value;

					break;

				case '/':

					s_lvl /= value;

					break;

				default:



					break;
				}

				break;

			default:

				break;
			}

			return s_lvl;

		}



		void set(int value)
		{

			lvl(0, value, ' ');// ' ' is there only because I need to send something

		}



		int get()
		{

			return lvl(2, 0, ' ');//0 and ' ' are there only because you need to send something

		}



		void edit(int value, char operation)
		{

			lvl(1, value, operation);

		}

	}

}
