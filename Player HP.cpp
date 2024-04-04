
#include <iostream>
//#include "Player Stats.h"



namespace Player
{

	namespace Health
	{

		double health(short action, double value, char operation)
		{

			static double s_health{ 0 };


			switch (action)
			{
			case 0://set

				s_health = value;

				break;

			case 1://edit

				switch (operation)
				{
				case '+':

					s_health += value;

					break;

				case '-':

					s_health -= value;

					break;

				case '*':

					s_health *= value;

					break;

				case '/':

					s_health /= value;

					break;

				default:



					break;
				}

				break;

			default:

				break;
			}

			return s_health;

		}



		void set(double value)
		{

			health(0, value, ' ');// ' ' is there only because I need to send something

		}



		double get()
		{

			return health(2, 0, ' ');//0 and ' ' are there only because you need to send something

		}



		void edit(double value, char operation)
		{

			health(1, value, operation);

		}



		//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\\



		double maxHealth(short action, double value, char operation)
		{

			static double s_health{ 0 };

			switch (action)
			{
			case 0://set

				s_health = value;

				break;

			case 1://edit

				switch (operation)
				{
				case '+':

					s_health += value;

					break;

				case '-':

					s_health -= value;

					break;

				case '*':

					s_health *= value;

					break;

				case '/':

					s_health /= value;

					break;

				default:



					break;
				}

				break;

			default:

				break;
			}
			return s_health;

		}



		void setMax(double value)
		{

			maxHealth(0, value, ' ');// ' ' is there only because I need to send something

		}



		double getMax()
		{

			return maxHealth(2, 0, ' ');//0 and ' ' are there only because you need to send something

		}



		void editMax(double value, char operation)
		{

			maxHealth(1, value, operation);

		}

	}

}