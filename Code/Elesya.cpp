
#include <iostream>
#include "Talk To Encounters English.h"
#include "Parla Con Gli Incontri.h"
#include "Everywhere Used Func.h"
#include "Input.h"



bool elesya()
{
	int changer{ 0 };//0 answe again. 1 Kelmod. 2 Lenre
	char answer{ 0 };


	bool answerAgain{ false };

	std::cout << "Why are you still here? I need to make a surprise for Kelmod when "
		<< "Sila will come here tomorrow.\n"
		<< "So why don't you go and do what you would do if not here and close this game.\n";

	do
	{
		std::cin >> answer;
		switch (answer)
		{
		case 'y'://yes

			std::cout << "Good. Bye.\n";

			break;

		case 'n'://no

			std::cout << "What do you want? Know me more?\n";
			answer = Input::character();
			if (answer == 'y' || answer == 's')
			{

				std::cout << "Do you know Nanre is thinking and writng a book?\n"
					<< "He told me that I'll go in that book so I'll change game.\n"
					<< "And I should say that is for now a good game.\n"
					<< "This is the code:\n" << "#include <iostream>"
					<< "\nDo you like the game? Well I like the book and not the game.\n"
					<< "Now if you want to see the book ready before june go where he is "
					<< "and him tell to write it or I'll destroy him.\n";

			}
			else
			{

				std::cout << "Then what do you want? Can't you stress someone else like Kelmod?\n"
					<< "You know what? Kelmod come here!\n";
				kelmod(true);

			}
			break;

		case 'w'://Skip

			std::cout << "You can't skip me. I need to go but you can choose to stay with"
				<< " Kelmod or Lenre. Write the K or L for Kelmod or Lenre.\n";
			do
			{

				answer = Input::character();
				switch (answer)
				{
				case 'K':

					changer = 1;
					std::cout << "Kelmod come here!\n";
					kelmod(true);

					break;

				case 'L':

					changer = 2;
					lenre(true);

					break;

				case 'E':

					changer = 0;
					std::cout << "I know you like me but I'm not an option so answer again.\n";

					break;

				case 'S':

					changer = 0;
					std::cout << "She's not even here. Why do you want to talk to her? I'll let you "
						<< "answer again.\n";

					break;

				default:

					changer = 0;
					std::cout << "What did you wrote? Did you use capital letters?\n"
						<< "Write again your answer.\n";

					break;

				}

				break;

			} while (changer == 0);

			break;

		default:

			std::cout << "(Not possible)\n";

			break;
		}


	} while (answerAgain == true);



	return false;
}
