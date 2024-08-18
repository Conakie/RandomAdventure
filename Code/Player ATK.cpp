
#include <iostream>
//#include "Player Stats.h"



namespace Player
{

	namespace Attack
	{

		double attack(short action, double value, char operation)
		{

			static double s_attack{ 0 };

			switch (action)
			{
			case 0://set

				s_attack = value;

				break;

			case 1://edit

				switch (operation)
				{
				case '+':

					s_attack += value;

					break;

				case '-':

					s_attack -= value;

					break;

				case '*':

					s_attack *= value;

					break;

				case '/':

					s_attack /= value;

					break;

				default:



					break;
				}

				break;

			default:

				break;
			}
			return s_attack;

		}



		void set(double value)
		{

			attack(0, value, ' ');// ' ' is there only because I need to send something

		}



		double get()
		{

			return attack(2, 0, ' ');//0 and ' ' are there only because you need to send something

		}



		void edit(double value, char operation)
		{

			attack(1, value, operation);

		}



		//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\\

	

		double maxAttack(short action, double value, char operation)
		{

			static double s_attack{ 0 };

			switch (action)
			{
			case 0://set

				s_attack = value;

				break;

			case 1://edit

				switch (operation)
				{
				case '+':

					s_attack += value;

					break;

				case '-':

					s_attack -= value;

					break;

				case '*':

					s_attack *= value;

					break;

				case '/':

					s_attack /= value;

					break;

				default:



					break;
				}

				break;

			default:

				break;
			}
			return s_attack;

		}



		void setMax(double value)
		{

			attack(0, value, ' ');// ' ' is there only because I need to send something

		}



		double getMax()
		{

			return attack(2, 0, ' ');//0 and ' ' are there only because you need to send something

		}



		void editMax(double value, char operation)
		{

			attack(1, value, operation);

		}

	}

}
