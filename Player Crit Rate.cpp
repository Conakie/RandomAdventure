
#include <iostream>
//#include "Player Stats.h"



namespace Player
{

	namespace CritRate
	{

		double critRate(short action, double value, char operation)
		{

			static double s_critRate{ 0 };


			switch (action)
			{
			case 0://set

				s_critRate = value;

				break;

			case 1://edit

				switch (operation)
				{
				case '+':

					s_critRate += value;

					break;

				case '-':

					s_critRate -= value;

					break;

				case '*':

					s_critRate *= value;

					break;

				case '/':

					s_critRate /= value;

					break;

				default:



					break;
				}

				break;

			default:

				break;
			}

			return s_critRate;

		}



		void set(double value)
		{

			critRate(0, value, ' ');// ' ' is there only because I need to send something

		}



		double get()
		{

			return critRate(2, 0, ' ');//0 and ' ' are there only because you need to send something

		}



		void edit(double value, char operation)
		{

			critRate(1, value, operation);

		}

	}

}
