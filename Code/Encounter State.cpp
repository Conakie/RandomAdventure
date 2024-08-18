
#include <iostream>
//#include"Encounter Stats.h"



namespace Encounter
{

	namespace IsUnderAttack
	{

		bool isUnderAttack(short action, bool value, char operation)
		{

			static bool s_isUnderAttack{ false };

			switch (action)
			{
			case 0://set

				s_isUnderAttack = value;

				break;

			case 1://edit

				switch (operation)
				{
				case '!':

					s_isUnderAttack = !s_isUnderAttack;

					break;

				case '&':

					s_isUnderAttack = s_isUnderAttack && value;

					break;

				case '|':

					s_isUnderAttack = s_isUnderAttack || value;

					break;

				default:



					break;
				}

				break;

			default:

				break;
			}
			return s_isUnderAttack;

		}


		void set(bool value)
		{

			isUnderAttack(0, value, ' ');// ' ' is there only because I need to send something

		}



		bool get()
		{

			return isUnderAttack(2, 0, ' ');//0 and ' ' are there only because you need to send something

		}



		void edit(bool value, char operation)
		{

			isUnderAttack(1, value, operation);

		}

	}



	namespace CanTalk
	{

		bool canTalk(short action, bool value, char operation)
		{

			static bool s_canTalk{ false };

			switch (action)
			{
			case 0://set

				s_canTalk = value;

				break;

			case 1://edit

				switch (operation)
				{
				case '!':

					s_canTalk = !s_canTalk;

					break;

				case '&':

					s_canTalk = s_canTalk && value;

					break;

				case '|':

					s_canTalk = s_canTalk || value;

					break;

				default:



					break;
				}

				break;

			default:

				break;
			}

			return s_canTalk;

		}


		void set(bool value)
		{

			canTalk(0, value, ' ');// ' ' is there only because I need to send something

		}



		bool get()
		{

			return canTalk(2, 0, ' ');//0 and ' ' are there only because you need to send something

		}



		void edit(bool value, char operation)
		{

			canTalk(1, value, operation);

		}

	}



	namespace IsGone
	{

		bool isGone(short action, bool value, char operation)
		{

			static bool s_isGone{ false };

			switch (action)
			{
			case 0://set

				s_isGone = value;

				break;

			case 1://edit

				switch (operation)
				{
				case '!':

					s_isGone = !s_isGone;

					break;

				case '&':

					s_isGone = s_isGone && value;

					break;

				case '|':

					s_isGone = s_isGone || value;

					break;

				default:



					break;
				}

				break;

			default:

				break;
			}

			return s_isGone;
		}


		void set(bool value)
		{

			isGone(0, value, ' ');// ' ' is there only because I need to send something

		}



		bool get()
		{

			return isGone(2, 0, ' ');//0 and ' ' are there only because you need to send something

		}



		void edit(bool value, char operation)
		{

			isGone(1, value, operation);

		}

	}
}
