
#include <iostream>
#include "Talk To Encounters English.h"
#include "Parla Con Gli Incontri.h"
#include "Everywhere Used Func.h"
#include "Input.h"



bool kelmod(bool sendByElesya)
{
	char answer{ 0 };


	bool answerAgain{ false };



	if (sendByElesya == true)
	{

		std::cout << "(Kelmod) What do ya want Elesya?\n"
			<< "(Elesya) Please talk to this guy that doesn't want to go away.\n"
			<< "(Kelmod) Oky. But can you tell me a thing?\n"
			<< "(Elesya) Sure. Ask now or later.\n"
			<< "(Kelmod) You look so stressed recently so what is the cause?\n"
			<< "(Elesya) It's only more work than the usual. Nothing else.\n"
			<< "(Klemod) Oh then I'll go with this person here and wait for him to close th"
			<< "e app.\n" << "So now that she's gone did she told you anything interesting?\n\n";
		do
		{
			answer = Input::character();
			switch (answer)
			{
			case 'y'://yes

				std::cout << "\n(Kelmod) Oh no now I wanna know but knowing Nanre doesn't know "
					<< "how to use strings I won't be able to know. WHY NANRE?\n"
					<< "Anyway why don't we talk about something you can answer.\n"
					<< "Did ya know that Nanre is writing a book and after that he will create "
					<< "a game from that book?\n\n";
				do
				{
					answer = Input::character();
					switch (answer)
					{
					case 'y'://yes

						std::cout << "\nDid Elesya told ya about that? Anyway after that book "
							<< "will be complete we will change game and go in that game.\n"
							<< "If you want us to stay here don't worry we'll have to work"
							<< " more but it's not a problem. For me.\n"
							<< "Well it looks like I'll have to finish talking or Nanre will "
							<< "come and send me to see Sila with a kick.\n"
							<< "I won't say where he will kick me.\n"
							<< "Oh yes right I almost forgot, if you want to read and have access "
							<< "to the book and the beta of the other game ask Nanre.\n"
							<< "Now i seriously need to stop and let ya go.\n"
							<< "If you wanted longer dialogues wait for Nanre to understand how "
							<< "strings and arrays work.\nFor now bye, see ya next time.\n";
						answerAgain = false;

						break;

					case 'n'://no

						std::cout << "\nDidn't anyone told ya abuot that book and game?\n"
							<< "Strange. Anyway the name is a temporary name but it is called"
							<< " What the book.\nWhy is it called like this? Even Nanre doesn't "
							<< "know.\nThe book is the story of Eyil that i personally didn't "
							<< "meat but Sila did.\n" << "She told me she is an amazing "
							<< "person and knows how to use a sword.\n Maybe I'll be able "
							<< "to use a sword too.\n Nanre please if you can hear me, "
							<< "please give me lessons on how to use swords, pleaseee.\n"
							<< "Sorry maybe I went a bit off topic.\n"
							<< "Anyway if you want to know more way for an official announcement"
							<< " from Nanre.\n Or you can ask me because I know something more "
							<< "than anyone that's here.\nThere's only one person that knows "
							<< "more than me. And it is Nanre.\nAnd I should thank Sila when "
							<< "I see her.\nDid ya know that Eyil... Wait, is that a spoiler "
							<< "what am I about to say? mmmmm. Well to save ya from spoilers "
							<< "I won't say it.\nAnyway if you have time go and visit Consea."
							<< "\nFrom what I know is a really good region.\n And the capital "
							<< "is something you need to see.\n" << "Another thing ya need to "
							<< "see is a concert of Necoto and Nala.\nSila said it's the best "
							<< "thing on Asioki.\nRight ya don't know what Asioki is. It's the "
							<< "planet they live.\nNow I'll leave you and let ya close the app.\n";
						answerAgain = false;

						break;

					case 'w'://Skip

						std::cout << "Please I can't know what ya want to say with \"skip\".\n"
							<< "Now if you'll excuse (Kelmod goes in another room).\n"
							<< "(Lenre) Perche' Kelmod e' nell'altra stanza?. Oh be' non credo "
							<< "torni presto quindi ci vediamo all'annuncio del libro.\n";
						answerAgain = false;

						break;

					default:

						std::cout << "(Not possible)\n";
						answerAgain = true;

						break;

					}

				} while (answerAgain == true);

				break;

			case 'n'://no

				std::cout << "Usually Elesya says interesting things like:'Tomorrow is cake day "
					<< "so go and start working so tomorrow you'll have the day off.'\n"
					<< "Oh well. Nanre asked if I could find someone that knows the image and "
					<< "characters creations in c++.\nSo if you know that please contact him.\n"
					<< "I think he would gladly work with ya. Thanks to him I'm here now.\n"
					<< "Now talking about something else...\n"
					<< "How can I ask to Sila to stay here for more than a week?\n"
					<< "I've tried everything but no success. Please help me.\n"
					<< "If you have an answer to that please write it when Nanre will put an "
					<< "input with a string after this. Thank you.\n"
					<< "I'll let you go now. Do what you want after the app closes.\n";
				answerAgain = false;

				break;

			case 'w'://Skip

				std::cout << "Why the players of these days know only how to press skip?\n"
					<< "Anyway since I'm a good person I'll let ya answer again.\n\n";

				answer = Input::character();

				std::cout << "I was joking. I won't let you know what I would have said "
					<< "if ya pressed y or n.\nByeee.\n\n\n\n. .\n U\n";

				break;

			default:

				std::cout << "(Not possible)\n";
				answerAgain = true;

				break;
			}

		} while (answerAgain == true);


	}
	else
	{

		std::cout << "Wait a sec... Ya want to talk to me?\n\n";

		answer = Input::character();
		if (answer == 'y' || answer == 's')
		{

			std::cout << "Wow that's strange, not many want to talk to me...\n"
				<< "Well since ya wanna talk and ya cannot answer with more than a single letter"
				<< "...\nSince you're here I can tell ya that in about a month Nanre will "
				<< "tell us when the book and game will be officially announced.\n"
				<< "And maybe we could go into that ship I know but I don't remember the name.\n"
				<< "How was it called? Oh well I don't remember it.\nBut I know there is so "
				<< "much space that we could live there.\n I hope it'll be like so.\n"
				<< "If I remember correctly the ship is really cheap.\nOk maybe not.\n"
				<< "Mmmmmm Well the model before could be a lot cheper... Nope\n"
				<< "Ok forget what I just said.\nWanna see a face?\n\n";
			std::cin >> answer;

			if (answer == 'y' || answer == 's')
			{

				std::cout << "\n\nO O\n U\n\n\n"
					<< "I know you like that face. So now I'll leave ya because I need "
					<< "to write some suggestions to Nanre. Byeee\n";

			}
			else
			{

				std::cout << "Oh well it was a good one but what can ya do about that now?\n"
					<< "Anyway I'll let ya go because Nanre MUST see my suggestions "
					<< "about the ship. So byeee.\n";

			}

		}
		else
		{

			std::cout << "Yes it's always like this so see ya next time ya play.\n";

		}

	}


	return false;
}
