
#include <iostream>
//#include "Player Stats.h"



namespace Player
{

	namespace CritDmg
	{

		double critDmg(short action, double value, char operation)
		{

			static double s_critDmg{ 0 };


			switch (action)
			{
			case 0://set

				s_critDmg = value;

				break;

			case 1://edit

				switch (operation)
				{
				case '+':

					s_critDmg += value;

					break;

				case '-':

					s_critDmg -= value;

					break;

				case '*':

					s_critDmg *= value;

					break;

				case '/':

					s_critDmg /= value;

					break;

				default:



					break;
				}

				break;

			default:

				break;
			}

			return s_critDmg;

		}



		void set(double value)
		{

			critDmg(0, value, ' ');// ' ' is there only because I need to send something

		}



		double get()
		{

			return critDmg(2, 0, ' ');//0 and ' ' are there only because you need to send something

		}



		void edit(double value, char operation)
		{

			critDmg(1, value, operation);

		}

	}

}
