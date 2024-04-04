
#include <iostream>
//#include "Player Stats.h"



namespace Player
{

	namespace Xp
	{

		double xp(short action, double value, char operation)
		{

			static double s_xp{ 0 };


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



		void set(double value)
		{

			xp(0, value, ' ');// ' ' is there only because I need to send something

		}



		double get()
		{

			return xp(2, 0, ' ');//0 and ' ' are there only because you need to send something

		}



		void edit(double value, char operation)
		{

			xp(1, value, operation);

		}


		
		//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\\



		double lvlUpXp(short action, double value, char operation)
		{

			static double s_lvlUpXp{ 0 };


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



		void setlvlUpXp(double value)
		{

			lvlUpXp(0, value, ' ');// ' ' is there only because I need to send something

		}



		double getlvlUpXp()
		{

			return lvlUpXp(2, 0, ' ');//0 and ' ' are there only because you need to send something

		}



		void editlvlUpXp(double value, char operation)
		{

			lvlUpXp(1, value, operation);

		}

	}

}